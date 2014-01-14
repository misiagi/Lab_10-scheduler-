#include "stdafx.h"
#include "history.h"
#include <iostream>


history::history()
{
	cycleamount=0;
}

void history::add_cycle()
{
	cycleamount++;
}

void history::add_id(int id)
{
	ids.push_back(id);
}

void history::add_state(char* statestab)
{
	states.push_back(statestab);
}

void history::display()
{
	
	for(int j=0; j<ids.size(); j++)
	{
		std::cout<<ids[j]<<":	";
		for (int i=0; i<cycleamount; i++)
		{
			std::cout<<(states[i])[j];
		}
		std::cout<<std::endl;
		
	}
}
