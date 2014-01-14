#pragma once
#include <vector>
#include "process.h"
#include "strategy.h"

class SJF : public strategy
{
public:
	SJF(void);
	int make_order(std::vector<process*>, int);
};
