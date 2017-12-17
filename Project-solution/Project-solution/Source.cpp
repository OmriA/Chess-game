#include "Pipe.h"
#include "Player.h"
#include "Board.h"
#include <iostream>
#include <thread>

using namespace std;
void main()
{
	
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

	//strcpy_s(msgToGraphics, "rnbkqbnrpppppppp################################PPPPPPPPRNBKQBNR1"); // just example...
	strcpy_s(msgToGraphics, "rrrrrrrrrrrrrrrr################################RRRRRRRRRRRRRRRR1"); // just example...
	board.initBoard(msgToGraphics);
	board.printBoard();
	turn = int(msgToGraphics[64] - '0');

	p.sendMessageToGraphics(msgToGraphics);   // send the board string

	// get message from graphics
	string msgFromGraphics = p.getMessageFromGraphics();

	while (msgFromGraphics != "quit")
	{
		char flag;
		// should handle the string the sent from graphics
		// according the protocol. Ex: e2e4           (move e2 to e4)
		
		Location src(unsigned int(msgFromGraphics[1] - '0'), msgFromGraphics[0]);
		Location dst(unsigned int(msgFromGraphics[3] - '0'), msgFromGraphics[2]);

		flag = board.getIndex(src)->isLegal(board, turn, src, dst);
		strcpy_s(msgToGraphics, "" + flag); // msgToGraphics should contain the result of the operation



		// return result to graphics		
		p.sendMessageToGraphics(msgToGraphics);   

		// get message from graphics
		msgFromGraphics = p.getMessageFromGraphics();
	}

	p.close();
}