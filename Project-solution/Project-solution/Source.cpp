#include "Pipe.h"
#include "Player.h"
#include "Board.h"
#include <iostream>
#include <thread>

using namespace std;
void main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	srand(time_t(NULL));

	Board board;
	Pipe p;
	bool isConnect = p.connect();
	int turn = 0;

	string ans;
	while (!isConnect)
	{
		cout << "cant connect to graphics" << endl;
		cout << "Do you try to connect again or exit? (0-try again, 1-exit)" << endl;
		cin >> ans;

		if (ans == "0")
		{
			cout << "trying connect again.." << endl;
			Sleep(5000);
			isConnect = p.connect();
		}
		else
		{
			p.close();
			return;
		}
	}


	char msgToGraphics[1024];
	// msgToGraphics should contain the board string accord the protocol

	strcpy_s(msgToGraphics, "rnbkqbnrpppppppp################################PPPPPPPPRNBKQBNR1"); // just example...
	//strcpy_s(msgToGraphics, "rrrrrrrrrrrrrrrr################################RRRRRRRRRRRRRRRR1"); // just example...
	board.initBoard(msgToGraphics);
	if (msgToGraphics[64] != '0')
	{
		turn = 0;
	}
	else
	{
		turn = 1;
	}
	p.sendMessageToGraphics(msgToGraphics);   // send the board string

	// get message from graphics
	board.printBoard();
	string msgFromGraphics = p.getMessageFromGraphics();

	while (msgFromGraphics != "quit")
	{
		char flag = 0;
		// should handle the string the sent from graphics
		// according the protocol. Ex: e2e4           (move e2 to e4)

		Location src(BOARD_SIZE - 1 - unsigned int(msgFromGraphics[1] - '1'), msgFromGraphics[0]);
		Location dst(BOARD_SIZE - 1 - unsigned int(msgFromGraphics[3] - '1'), msgFromGraphics[2]);

		flag = board.getIndex(src)->isLegal(board, turn, src, dst, false);
		msgToGraphics[0] = flag;
		msgToGraphics[1] = 0;	// msgToGraphics should contain the result of the operation

		// return result to graphics		
		p.sendMessageToGraphics(msgToGraphics);

		// get message from graphics
		if (flag == '0' || flag == '1')
		{
			board.printBoard();
			if (turn)
			{
				turn = 0;
			}
			else
			{
				turn = 1;
			}
		}
		msgFromGraphics = p.getMessageFromGraphics();
	}
	board.freeBoard();
	p.close();
}