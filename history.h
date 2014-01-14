#pragma once
#include <vector>

class history
{
private:
	int cycleamount;
	std::vector< int > ids;
	std::vector< char* > states;
public:
	void add_cycle();
	void add_id(int);
	void add_state(char*);
	history();
	void display();
};
