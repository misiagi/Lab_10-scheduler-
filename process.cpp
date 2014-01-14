#include "stdafx.h"
#include "process.h"


process::process(int id,int moves,int max_move_time)
{
	this -> id = id;
	this -> moves = moves;
	this-> max_move_time = max_move_time;
	this->moves_left = moves;
	this->state = 'W';
}
