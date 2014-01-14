#include "stdafx.h"
#include "user.h"
#include <iostream>
#include "FIFO.h"
#include "SJF.h"


void user::init_process(int amount,int* ids, int* movestab, int* move_time_tab)
{
	for (int i=0; i<amount; i++)
	{
		processvec.push_back( new process(ids[i], movestab[i], move_time_tab[i]) );
		lastp_id = ids[i];
	}
}

void user::FIFO_strategy()
{
	delete p_strategy;
	p_strategy = new FIFO;
}

void user::SJF_strategy()
{
	delete p_strategy;
	p_strategy = new SJF;
}

void user::sim_process()
{
	int exitstates=0;
	
	int i = 0;

	delete phistory;
	phistory = new history; 

	lastp_id = processvec.at(processvec.size()-1)->id; 
	for(int j=0; j<processvec.size(); j++) 
	{
		phistory->add_id(processvec[j]->id);
	}
	
	while(1)
	{
		
		for(int u=0; u<processvec.size(); u++)
		{
			processvec[u]->move_time = rand()%processvec[i]->max_move_time; 
			if(processvec[u]->move_time == 0)							  
				processvec[u]->move_time = 1;
			}
			
		}


		i = p_strategy->make_order(processvec, lastp_id); 

		lastp_id = processvec[i]->id;
	

		if(processvec[i]->moves_left > 0)
		{
			
			
			

			for(int j=0; j<processvec[i]->move_time; j++)
			{

				for(int k=0; k<processvec.size(); k++)
				{
					if(k == i)
					{
					processvec[k]->state = 'D';
					}
					else if(processvec[k]->state != 'Z')
					{
						processvec[k]->state = 'W';
					}
				}
				
					phistory->add_cycle();

					char* temp = new char[processvec.size()];

					for(int l=0; l<processvec.size(); l++)
					{
						temp[l] = processvec[l]->state;
					}
					phistory->add_state(temp);
					//
				
			}
			processvec[i]->moves_left--;
			if(processvec[i]->moves_left == 0)
			{
				processvec[i]->state = 'Z';
				exitstates++;
			}
		

		}
		
		

		if(exitstates == processvec.size())
		{
			break;
		}
	}
}

void user::clear_process_vector()
{
	while(processvec.size() > 0)
	{
		delete processvec[processvec.size()-1];
		processvec.pop_back();
	}
}
