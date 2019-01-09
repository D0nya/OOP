#pragma once
#include "Advt.h"

class WTB : virtual public Advt{
private:
	string state;
public:
	WTB();
	WTB(const WTB&);
	//getters
	string get_state();
	//setters
	void set_state(string state);

	void get_info();
};