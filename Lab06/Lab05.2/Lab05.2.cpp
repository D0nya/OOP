#include "stdafx.h"
#include "WTB.h"
#include "WTS.h"
#include "Rent.h"
#include "Work.h"
#include "list.h"

using namespace std;

int wallet = 100;
string owner;

		
template<class T> T* temp() {
	T *temp = new T();
	temp->set_owner(owner);
	return temp;
}

template<class T> void edit(stack<T*> &st, int size) {
	int i, n;
	char t[8], kod;
	string temp;
	cout << "Choose an advt: "; cin >> t;
	for (i = 0; i < strlen(t); i++) {
		if (isalpha(t[i])) {
			cout << "Enter number! " << endl;
			return;
		}
		else
			n = atoi(t);
	}
	if (n <= 0 || n > size) {
		cout << "out of stack!" << endl;
		return;
	}

	n--;
	cout << "1. Edit name;\n2. Edit number;\n3. Delete\n" << endl;
	cin >> kod;
	switch (kod) {
	case '1':
		cout << "Enter name: "; cin >> temp;
		st[n]->set_name(temp);
		return;
	case '2':
		cout << "Enter phone number: "; cin >> temp;
		st[n]->set_phone(temp);
		return;
	case '3':
		st.del_el(st[n]);
		return;
	}
}

int main()
{
	int i, size;
	char kod, t2;
	cout << "Enter username: ";
	cin >> owner;

	stack<WTB*> buy; WTB *tb = NULL;
	stack<WTS*> sell; WTS *ts = NULL;
	stack<Rent*> rent; Rent *tr = NULL;
	stack<Work*> work; Work *tw = NULL;

	while (true) {
		cout <<  "\t\t\t\t\t\t\t\t" << wallet << "$" << endl;
		cout << "1. Add advt\n2. Show advts\n3. Edit your advts\nELSE. EXIT\n";
		cin >> kod;
		switch (kod) {
		case '1':
			cout << endl;
			cout << "You should pay, to add an advt!" << endl;
			cout << "Buy: 10$" << endl;
			cout << "Sell: 10$" << endl;
			cout << "Rent: 15$" << endl;
			cout << "Work: 20$" << endl << endl;
			cout << "What advt do you want to add: \n1. I Want To Buy\n2. I Wnat To Sell\n3. Rent\n4. Work\n0.EXIT\n";
			cin >> kod;
			switch (kod) {
			case '1':
				buy.Push(temp<WTB>());
				buy[buy.stack_size() - 1]->pay(wallet);
				break;
			case '2':
				sell.Push(temp<WTS>());
				sell[sell.stack_size() - 1]->pay(wallet);

				break;
			case '3':
				rent.Push(temp<Rent>());
				rent[rent.stack_size() - 1]->pay(wallet);

				break;
			case '4':
				work.Push(temp<Work>());
				work[work.stack_size() - 1]->pay(wallet);

				break;
			default:
				break;
			}
			break;
		case '2':
			cout << "WTB ADVTs" << endl << "---------" << endl;
			for (i = 0; i < buy.stack_size(); i++) {
				cout << i + 1 << ". ";
				buy[i]->get_info();
			}

			cout << "WTS ADVTs" << endl << "---------" << endl;
			for (i = 0; i < sell.stack_size(); i++) {
				cout << i + 1 << ". ";
				sell[i]->get_info();
			}

			cout << "RENT ADVTs" << endl << "----------" << endl;
			for (i = 0; i < rent.stack_size(); i++) {
				cout << i + 1 << ". ";
				rent[i]->get_info();
			}

			cout << "WORK ADVTs" << endl << "----------" << endl;
			for (i = 0; i < work.stack_size(); i++) {
				cout << i + 1 << ". ";
				work[i]->get_info();
			}
			break;

		case '3':
			size = 0;
			cout << "Choose category:" << endl << " 1. WTB\n 2. WTS\n 3. Rent\n 4. Work\n" << endl; cin >> t2;

			switch (t2) {
			case '1':
				cout << "YOUR ADVTs: " << endl;
				cout << "WTB ADVTs" << endl << "---------" << endl;
				for (i = 0; i < buy.stack_size(); i++) {
					if (buy[i]->get_owner() == owner) {
						cout << i + 1 << ". ";
						buy[i]->get_info();
						size++;
					}
				}
				if (size != 0)
					edit(buy, size);
				else
					cout << "No advts" << endl << endl;
				break;

			case '2':
				cout << "WTS ADVTs" << endl << "---------" << endl;
				for (i = 0; i < sell.stack_size(); i++) {
					if (sell[i]->get_owner() == owner) {
						cout << i + 1 << ". ";
						sell[i]->get_info();
						size++;
					}
				}
				if (size != 0)
					edit(sell, size);
				else
					cout << "No advts" << endl << endl;
				break;

			case '3':
				cout << "RENT ADVTs" << endl << "----------" << endl;
				for (i = 0; i < rent.stack_size(); i++) {
					if (rent[i]->get_owner() == owner) {
						cout << i + 1 << ". ";
						rent[i]->get_info();
						size++;
					}
				}
				if (size != 0)
					edit(rent, size);
				else
					cout << "No advts" << endl << endl;
				break;


			case '4':
				cout << "WORK ADVTs" << endl << "----------" << endl;
				for (i = 0; i < work.stack_size(); i++) {
					if (work[i]->get_owner() == owner) {
						cout << i + 1 << ". ";
						work[i]->get_info();
						size++;
					}
				}
				if (size != 0)
					edit(work, size);
				else
					cout << "No advts" << endl << endl;
				break;

			}
			break;
		default:
			return 0;
		}
	}
	return 0;
}