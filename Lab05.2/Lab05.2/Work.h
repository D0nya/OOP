#pragma once
#include "WTS.h"

class Work : public WTS {
private:
	string adress;
	string position;
public:
	Work();
	Work(string adress, string position, int award);
	Work(const Work&);
	//getters
	string get_adress();
	string get_position();
	//setters
	void set_adress(string adress);
	void set_position(string position);

	void get_info();
};
