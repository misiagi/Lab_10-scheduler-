#pragma once
#include <vector>
#include "process.h"

class strategy
{
public:
	strategy(void);
	virtual int make_order(std::vector<process*>, int){return -1;};
};
