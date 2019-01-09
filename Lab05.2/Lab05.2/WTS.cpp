#include "stdafx.h"
#include "WTS.h"

using namespace std;

WTS::WTS() {
	aprice = 10;
	char t[128]; bool txt = true;
	int i = 0;
	while (txt) {
		cout << "Enter price: ";
		cin >> t;
		for (i = 0; i < strlen(t); i++) {
			if (isalpha(t[i])) {
				cout << "Price must be a number!" << endl;
				break;
			}
			if (atoi(t) <= 0)
				cout << "Price can't be less than 0!\n";
			if (i == strlen(t) - 1) {
				txt = false;
			}
		}
	}
	price = atoi(t);
}
WTS::WTS(int tprice) {
	price = tprice;
}
WTS::WTS(const WTS &temp) : Advt(temp) {
	price = temp.price;
}
//getter s
int WTS::get_price() { return price; }
//setters
void WTS::set_price(int tprice) { price = tprice; }

void WTS::get_info() {
	Advt::get_info();
	cout << "Price: " << price << endl << endl;
}