#include "stdafx.h"
#include "WTB.h"

using namespace std;

WTB::WTB() {
	aprice = 10;
	int k, i; char t[32];
	bool txt = true;
	cout << "Choose state: \n1. new\n2. normal\n3. damaged\n4. bad state" << endl;

	while (txt) {
		cin >> t;
		for (i = 0; i < strlen(t); i++) {
			if (isalpha(t[i])) {
				cout << "Enter a number!" << endl;
				break;
			}
			if (i == strlen(t) - 1) {
				txt = false;
			}
		}
		k = atoi(t);
		if (k < 1 || k > 4) {
			cout << "Number must be from 1 to 4!" << endl;
			txt = true;
		}
	}

	switch (k) {
	case 1:
		state = "new";
		break;
	case 2:
		state = "normal";
		break;
	case 3:
		state = "damaged";
		break;
	case 4:
		state = "bad state";
		break;
	}
}

WTB::WTB(const WTB &temp) : Advt(temp) {
	
	state = temp.state;
}

//getters
string WTB::get_state() { return state; }
//setters
void WTB::set_state(string tstate) { state = tstate; }

void WTB::get_info(){
	Advt::get_info();
	cout << "State: " << state << endl << endl;
}