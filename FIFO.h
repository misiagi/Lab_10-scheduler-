#pragma once
#include <vector>
#include "process.h"
#include "strategy.h"

class FIFO : public strategy
{
public:
	FIFO(void);
	int make_order(std::vector<process*>, int);
};
