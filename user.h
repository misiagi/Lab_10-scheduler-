#pragma once
#include "process.h"
#include <vector>
#include "strategy.h"

class user
{
private:
	std::vector<process*> processvec;
	int lastp_id;
public:
	void init_process(int, int*, int*, int*);
	void sim_process();
	history* phistory;
	strategy* p_strategy;
	void FIFO_strategy();
	void SJF_strategy();
	void clear_process_vector();
};
