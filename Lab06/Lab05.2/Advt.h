#pragma once
#include <string>
#include <iostream>

using namespace std; 



class Advt {
private:
	string name;
	string phone_number;
	string owner;
protected:
	int aprice;
public:
	Advt();
	Advt(string name, string phone, string owner);
	Advt(const Advt&);
	virtual ~Advt();
		//getters
	string get_name();
	string get_phone();
	string get_owner();
		//setters
	void set_name(string t);
	void set_phone(string t);
	void set_owner(string t);

	virtual void get_info(void) = 0;

	void pay(int& wal);
	int getaprice() { return aprice; }

};