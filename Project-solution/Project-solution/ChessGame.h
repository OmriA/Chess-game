#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <exception>
#include "Location.h"

using std::string;
using std::vector;

//colors
#define EMPTY -1
#define BLACK 0
#define WHITE 1

//code to front-end
#define VALID_MOVE '0'
#define VALID_CHECK '1'
#define SRC_HAS_NO_TURNS_TOOL '2'
#define DST_HAS_TURNS_TOOL '3'
#define INVALID_CHECK '4'
#define INVALID_MOVE '6'
#define SAME_SRC_DST '7'
#define CHECKMATE '8'

//moves options
#define VERTICAL 0
#define HORIZONTAL 1
#define DIAGONAL 2