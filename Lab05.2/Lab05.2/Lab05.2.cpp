// Lab05.2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "WTB.h"
#include "WTS.h"
#include "Rent.h"
#include "Work.h"
#include <list>

using namespace std;

string owner;
//void edit(list<WTB> &buy, list<WTS> &sell, list<Rent> &rent, list<Work> &work, int size);

class A {
private:
	int id;
public:

	A(int i) { id = i; }

	virtual void get() {
		cout << id << endl;
	}
};

class B : public A{
private:
	char *name;
public:
	B(char *n, int i) : A(i){
		name = new char[strlen(n) + 1];
		strcpy(name, n);
	}
	void get() {
		A::get();
		cout << name << endl;
	}
};


class C : public B{
private:
	char *sname;
public:
	C(char *sn, char *n, int i) : B(n, i){
		sname = new char[strlen(sn) + 1];
		strcpy(sname, sn);
	}
	void get() {
		B::get();
		cout << sname << endl;
	}
};




int main() {
	int id;
	char name[129], sname[129];

	cin >> id;
	cin >> name;
	cin >> sname;

	C c(sname, name, id);
	c.get();
	return 0;
}

/*
int main()
{
	int i, size;
	char kod;
	cout << "Enter username: ";
	cin >> owner;

	list<WTB> buy;
	list<WTS> sell;
	list<Rent> rent;
	list<Work> work;

	sell.push_back(WTS());
	sell.back().set_owner("VITALIY TSAL'");

	while (true) {
		cout << "1. Add advt\n2. Show advts\n3. Edit your advts\nELSE. EXIT\n";
		cin >> kod;
		switch (kod) {
		case '1':
			cout << "What advt do you want to add: \n1. I Want To Buy\n2. I Wnat To Sell\n3. Rent\n4. Work\n0.EXIT\n";
			cin >> kod;
			switch (kod) {
			case '1':
				buy.push_back(WTB());
				buy.back().set_owner(owner);
				break;
			case '2':
				sell.push_back(WTS());
				sell.back().set_owner(owner);
				break;
			case '3':
				rent.push_back(Rent());
				rent.back().set_owner(owner);
				break;
			case '4':
				work.push_back(Work());
				work.back().set_owner(owner);
				break;
			default:
				break;
			}
			break;
		case '2':
			i = 1;
			cout << "WTB ADVTs" << endl << "---------" << endl;
			for (auto b : buy) {
				cout << i << ". ";
				b.get_info();
				i++;
			}
			i = 1;
			cout << "WTS ADVTs" << endl << "---------" << endl;
			for (auto s : sell) {
				cout << i << ". ";
				s.get_info();
				i++;
			}
			i = 1;
			cout << "RENT ADVTs" << endl << "----------" << endl;
			for (auto r : rent) {
				cout << i << ". ";
				r.get_info();
				i++;
			}
			i = 1;
			cout << "WORK ADVTs" << endl << "----------" << endl;
			for (auto w : work) {
				cout << i << ". ";
				w.get_info();
				i++;
			}
			break;
		case '3':
			cout << endl;
			i = 1;
			for (auto b : buy) {
				if (b.get_owner() == owner) {
					cout << i << ". ";
					b.get_info();
					i++;
				}
			}
			for (auto s : sell) {
				if (s.get_owner() == owner) {
					cout << i << ". ";
					s.get_info();
					i++;
				}
			}
			for (auto r : rent) {
				if (r.get_owner() == owner) {
					cout << i << ". ";
					r.get_info();
					i++;
				}
			}
			for (auto w : work) {
				if (w.get_owner() == owner) {
					cout << i << ". ";
					w.get_info();
					i++;
				}
			}
			if (i == 1) {
				cout << "You don't have advts!" << endl;
				break;
			}
			size = i;
			edit(buy, sell, rent, work, size);
			break;
		default:
			return 0;
		}
	}
}

//void edit(list<WTB> &buy, list<WTS> &sell, list<Rent> &rent, list<Work> &work, int size) {
//	int i, n;
//	char t, t2[8];
//	string temp;
//
//	cout << "Choose number of advt: "; cin >> t2;
//	for (i = 0; i < strlen(t2); i++) {
//		if (isalpha(t2[i])) {
//			return;
//		}
//		else if (atoi(t2) > size || atoi(t2) <= 0) {
//			cout << "Out of stack!" << endl;
//			return;
//		}
//		else
//			n = atoi(t2);
//	}
//
//	i = 1;
//	for (auto &b : buy) {
//		if (b.get_owner() == owner) {
//			cout << i << ". ";
//			b.get_info();
//			if (i == n) {
//				cout << "1. edit name\n2. edit phone number\n3. edit state\n";
//				cin >> t;
//				switch (t) {
//				case '1':
//					cout << "Enter name: "; cin >> temp;
//					b.set_name(temp);
//					cout << b.get_name();
//					return;
//				case '2':
//					cout << "Enter phone number: "; cin >> temp;
//					b.set_phone(temp);
//					return;
//				case '3':
//					cout << "Enter state: "; cin >> temp;
//					b.set_state(temp);
//					return;
//				default: return;
//				}
//			}
//			i++;
//		}
//	}
//	for (auto &s : sell) {
//		if (s.get_owner() == owner) {
//			cout << i << ". ";
//			s.get_info();
//			if (i == n) {
//				cout << "1. edit name\n2. edit phone number\n3. edit price\n";
//				cin >> t;
//				switch (t) {
//				case '1':
//					cout << "Enter name: "; cin >> temp;
//					s.set_name(temp);
//					return;
//				case '2':
//					cout << "Enter phone number: "; cin >> temp;
//					s.set_phone(temp);
//					return;
//				case '3':
//					while (i == n) {
//						cout << "Enter price: "; cin >> t2;
//						for (int j = 0; j < strlen(t2); j++) {
//							if (isalpha(t2[j])) {
//								cout << "Enter number!\n";
//								continue;
//							}
//							else
//								i = -1;
//						}
//					}
//					s.set_price(atoi(t2));
//					return;
//				default: return;
//				}
//			}
//			i++;
//		}
//	}
//	for (auto &r : rent) {
//		if (r.get_owner() == owner) {
//			cout << i << ". ";
//			r.get_info();
//			if (i == n) {
//				cout << "1. edit name\n2. edit phone number\n3. edit price\n4. edit state";
//				cin >> t;
//				switch (t) {
//				case '1':
//					cout << "Enter name: "; cin >> temp;
//					r.set_name(temp);
//					return;
//				case '2':
//					cout << "Enter phone number: "; cin >> temp;
//					r.set_phone(temp);
//					return;
//				case '3':
//					while (i == n) {
//						cout << "Enter price: "; cin >> t2;
//						for (int j = 0; j < strlen(t2); j++) {
//							if (isalpha(t2[j])) {
//								cout << "Enter number!\n";
//								continue;
//							}
//							else
//								i = -1;
//						}
//					}
//					r.set_price(atoi(t2));
//					return;
//				case '4':
//					cout << "Enter state: "; cin >> temp;
//					r.set_state(temp);
//					return;
//				default: return;
//				}
//			}
//			i++;
//		}
//	}
//	for (auto &w : work) {
//		if (w.get_owner() == owner) {
//			cout << i << ". ";
//			w.get_info();
//			if (i == n) {
//				cout << "1. edit name\n2. edit phone number\n3. edit price\n4. edit adress\n5. edit position";
//				cin >> t;
//				switch (t) {
//				case '1':
//					cout << "Enter name: "; cin >> temp;
//					w.set_name(temp);
//					return;
//				case '2':
//					cout << "Enter phone number: "; cin >> temp;
//					w.set_phone(temp);
//					return;
//				case '3':
//					while (i == n) {
//						cout << "Enter price: "; cin >> t2;
//						for (int j = 0; j < strlen(t2); j++) {
//							if (isalpha(t2[j])) {
//								cout << "Enter number!\n";
//								continue;
//							}
//							else
//								i = -1;
//						}
//					}
//					w.set_price(atoi(t2));
//					return;
//				case '4':
//					cout << "Enter adress: "; cin >> temp;
//					w.set_adress(temp);
//					return;
//				case '5':
//					cout << "Enter position: "; cin >> temp;
//					w.set_position(temp);
//					return;
//				default: return;
//				}
//			}
//			i++;
//		}
//		return;
//	}
//}

*/