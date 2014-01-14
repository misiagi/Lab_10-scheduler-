#pragma once
#include "history.h"

class process
{
public:
	int id;
	char state;
	int moves;
	int moves_left;
	int max_move_time;
	int move_time;
	process(int,int,int);

	
};
