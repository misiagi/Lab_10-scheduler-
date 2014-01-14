#include "stdafx.h"
#include "user.h"
#include "process.h"
#include "history.h"
#include <iostream>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	user new_user;

	int ids[8] = {1,2,3,4,5,6,7,8};
	int moves[8] = {2,3,1,2,1,2,5,3};
	int moves_time[8] = {3,2,3,5,2,5,2,5}; 

	new_user.init_process(8, ids, moves, moves_time);

	new_user.FIFO_strategy(); 

	new_user.sim_process();

	(new_user.phistory)->display();

	cout<<endl<<endl;

	new_user.clear_process_vector(); 
	
	//------------------------------------------------------------

	new_user.init_process(8, ids, moves, moves_time); 

	new_user.SJF_strategy(); 

	new_user.sim_process();
	
	(new_user.phistory)->display();

	getchar();
}

