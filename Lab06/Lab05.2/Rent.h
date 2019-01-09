#pragma once
#include "WTB.h"
#include "WTS.h"

class Rent : virtual public WTB, virtual public WTS{
private:
	int percent;
	int term;	//month
	double spm;	//sum per month
public:
	Rent();
	Rent(int a) {
		aprice = 15;
	}

	Rent(const Rent&);
	//getters
	int get_percent();
	int get_term();
	double get_spm();
	//setters
	void set_percent(int percent);
	void set_term(int term);
	
	void get_info();
};