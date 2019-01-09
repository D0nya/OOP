#include "stdafx.h"
#include "Advt.h"

using namespace std;

Advt::Advt() {
	cout << "Enter name: ";
	cin >> name;
	cout << "Enter phone number: ";
	cin >> phone_number;
}

Advt::Advt(string tname, string tphone, string towner) {
	name = tname;
	phone_number = tphone;
	owner = towner;
}

Advt::Advt(const Advt& temp) {
	name = temp.name;
	phone_number = temp.phone_number;
	owner = temp.owner;
}

Advt::~Advt() {

}

//getters
string Advt::get_name() { return name; }
string Advt::get_phone() { return phone_number; }
string Advt::get_owner() { return owner; }
//setters
void Advt::set_name(string t) { name = t; }
void Advt::set_phone(string t) { phone_number = t; }
void Advt::set_owner(string t) { owner = t; }

void Advt::get_info() {
	cout << "Name: " << name << endl << "Phone number: " << phone_number << endl << "Owner: " << owner << endl;
}

void Advt::pay(int &wal) {
	wal -= aprice;
	if (wal < 0) {
		cout << "Not enough money" << endl;
		wal += aprice;
	}
	else
		cout << "success!" << endl;
}