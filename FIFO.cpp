#include "stdafx.h"
#include "FIFO.h"
#include <iostream>


FIFO::FIFO(void)
{
}


int FIFO::make_order(std::vector<process*> processvec, int lastp_id)
{
	
	for( int i=0; i<processvec.size(); i++)
	{
		if(processvec[i]->id == lastp_id)
		{
			if(i == processvec.size()-1)
			{
				return 0;
			}
			else
			{
				return i+1;
			}
		}
	}
}
