#pragma once
#include "Advt.h"

class WTS : virtual public Advt{
private:
	int price;
public:
	WTS();
	WTS(int a) {
		aprice = 10;
	}

	WTS(const WTS&);
	//getters
	int get_price();
	//setters
	void set_price(int price);

	void get_info();
};