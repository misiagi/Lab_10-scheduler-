#include "stdafx.h"
#include "SJF.h"
#include <iostream>

SJF::SJF(void)
{
}


int SJF::make_order(std::vector<process*> processvec, int lastp_id)
{
	int min = 9999999;
	int index=-1;
	for(int i=0; i<processvec.size(); i++) //znalezienie procesu niebedacego ostatnim wykonywanym i posiadajacego minimalny czas kroku
	{
		if((processvec[i]->id != lastp_id) && (processvec[i]->state != 'Z'))
		{
			if(processvec[i]->move_time < min)
			{
				min = processvec[i]->move_time;
				index = i;
			}
		}
	}

	if(index == -1) //zabezpieczenie gdy na koniec symulacji zostanie jeden proces z wiecej niz jednym ruchem
	{
		for(int i=0; i<processvec.size(); i++)
		{
			if(processvec[i]->id == lastp_id)
			{
				index = i;
			}
		}
	}
	return index;
}
