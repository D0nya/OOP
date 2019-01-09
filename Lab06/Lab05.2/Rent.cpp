#include "stdafx.h"
#include "Rent.h"
#include <iomanip>

using namespace std;

Rent::Rent() {
	aprice = 15;
	string tstate = get_state();
	int tprice = get_price();
	term = 12;	//months
	if (tstate == "new")
		percent = 10;
	else if (tstate == "normal")
		percent = 7;
	else if (tstate == "damaged")
		percent = 5;
	else
		percent = 3;
	spm = (tprice + tprice / percent) / term;
}

Rent::Rent(const Rent& temp) : WTB(temp), WTS(temp), Advt(temp) {
	percent = temp.percent;
	term = temp.term;
	spm = temp.spm;
}
//getters
int Rent::get_percent() { return percent; }
int Rent::get_term() { return term; }
double Rent::get_spm() { return spm; }
//setters
void Rent::set_percent(int tpercent) { percent = tpercent; }
void Rent::set_term(int tterm) { term = tterm; }

void Rent::get_info() {
	WTB::get_info();
	cout << setprecision(1)<< fixed << "Percent: " << percent << endl << "Sum per month: " << spm << "$" << endl << "Term: " << term << " months" << endl << endl;
}
