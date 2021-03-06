#include "stdafx.h"
#include <iostream>
#include <string.h>
#include <fstream>

using namespace std;

struct Advt {				//--Декларация двунаправленного списка--//
	char *name;
	char *phone_num;
	char *category;
	int price;
};

struct Spis2 {
	Spis2 *next;
	Spis2 *prev;
	Advt *ad;
};
											//--Декларация прототипов функций пользователя--//
void Create_Advt(Spis2**, Spis2**, char*, char*, char*, int);			// Функция создания первого элемента
void Add_Advt(int, Spis2**, Spis2**, char*, char*, char*, int);		// Функция добавления элемента
void View_Advt(int, Spis2*);									// Функция просмотра двунаправленного списка
void Del_All(Spis2**);												// Функция очистки памяти
void fillFile(string, int, Spis2*);

int main()
{
	int kod, price;
	char tname[200], tphonenum[200], tcat[200];
	char *name, *phonenum, *cat;
	char Str[2][10] = { "Begin", "End" };
	Spis2 *begin = NULL;
	Spis2 *end = NULL;
	Spis2 *t;
	string path = "file.txt";

	while (true) {
		cout << "\n\tCreate - 1.\n\tAdd    - 2.\n\tView   - 3.\n\tDel    - 4.\n\tWrite in file -5\n\tEXIT   - 0.\n\t";
		cin >> kod;
		switch (kod)
		{
		case 1:
			if (begin != NULL) {					
				cout << "Clear Memory!" << endl;
				break;
			}
			cout << "Enter name: "; cin >> tname;
			name = (char*)malloc(strlen(tname));
			strcpy(name, tname);
			cout << "Enter phone number: "; cin >> tphonenum;
			phonenum = (char*)malloc(strlen(tphonenum));
			strcpy(phonenum, tphonenum);
			cout << "Enter category: "; cin >> tcat;
			cat = (char*)malloc(strlen(tcat));
			strcpy(cat, tcat);
			cout << "Enter price: "; cin >> price;

			Create_Advt(&begin, &end, name, phonenum, cat, price);
			cout << "Created the first advt " <<  endl;
			break;
		case 2:
			cout << "Enter name: "; cin >> tname;
			name = (char*)malloc(strlen(tname) + 1);
			strcpy(name, tname);
			cout << "Enter phone number: "; cin >> tphonenum;
			phonenum = (char*)malloc(strlen(tphonenum) + 1);
			strcpy(phonenum, tphonenum);
			cout << "Enter category: "; cin >> tcat;
			cat = (char*)malloc(strlen(tcat));
			strcpy(cat, tcat);
			cout << "Enter price: "; cin >> price;

			cout << "Add Begin - 0, Add End - 1: "; cin >> kod;
			Add_Advt(kod, &begin, &end, name, phonenum, cat, price);
			if (kod == 0) t = begin;
			else t = end;
			cout << "Add to " << Str[kod] << endl;
			break;
		case 3:
			if (!begin) {
				cout << "Stack is Empty!" << endl;
				break;
			}
			cout << "View Begin - 0, View End - 1: "; cin >> kod;
			if (kod == 0) {
				t = begin;
				cout << "--Begin--" << endl;
			}
			else {
				t = end;
				cout << "--End--" << endl;
			}
			View_Advt(kod, t);
			break;
		case 4:
			if (begin != NULL) {
				Del_All(&begin);
			}
			cout << "Memory is Free!" << endl;
			break;
		case 5:
			fillFile(path, 0, begin);
			cout << "Success!" << endl;
			break;
		case 0:
			if (begin != NULL)
				Del_All(&begin);
			return 0;						
			break;
		}
	}

	return 0;
}

//--Функция создания первого элемента--//
void Create_Advt(Spis2 **begin, Spis2 **end, char *name, char *phone_num, char *cat, int price) {
	Spis2 *t = new Spis2;					
	t->ad = new Advt;
												
	t->ad->name = name;
	t->ad->phone_num = phone_num;
	t->ad->category = cat;
	t->ad->price = price;
	t->next = t->prev = NULL;			
	*begin = *end = t;						
}

//--Функция добавления элементов в список--//
void Add_Advt(int kod, Spis2 **begin, Spis2 **end, char *name, char *phone_num, char *cat, int price) {
	Spis2 *t = new Spis2;				
	t->ad = new Advt;
	t->ad->name = name;
	t->ad->phone_num = phone_num;	
	t->ad->category = cat;
	t->ad->price = price;

	switch (kod) {
	case 0:								//--Добавление элемента в начало списка--//
		t->prev = NULL;						
		t->next = *begin;					
		(*begin)->prev = t;				
		*begin = t;								
		break;
	case 1:								//--Добавление элемента в конец списка--//
		t->next = NULL;					
		t->prev = *end;					
		(*end)->next = t;				
		*end = t;								
	}
}

//--Функция просмотра списка--//
void View_Advt(int kod, Spis2 *t) {
	switch (kod) {
	case 0:															//--Просмотр списка с начала--//
		while (t != NULL) {								
			cout << " ADVT: " << t->ad->name << endl << " Phone number: " << t->ad->phone_num << endl << " Category: " << t->ad->category << endl << " Price: " << t->ad->price << endl << endl;
			t = t->next;									
		}
		break;
	case 1:															//--Просмотр списка с конца--//
		while (t != NULL) {								
			cout<< " ADVT: " << t->ad->name << endl << " Phone number: " << t->ad->phone_num << endl << " Category: " << t->ad->category << endl << " Price: " << t->ad->price << endl << endl;
			t = t->prev;										
		}
		break;
	}
}

void Del_All(Spis2 **p) {
	Spis2 *t = new Spis2;
	while (*p != NULL) {
		t = *p;
		*p = (*p)->next;
		delete t;
	}
}

void fillFile(string path, int kod, Spis2 *t) {
	ofstream fout;
	fout.open(path, ofstream::out);

	if (!fout.is_open())
	{
		cout << "Error" << endl;
		return;
	}

		while (t != NULL) {								
			fout << " " << " ADVT: " << t->ad->name << endl << " Phone number: " << t->ad->phone_num << endl << " Category: " << t->ad->category << " Price: " << t->ad->price << endl << endl;

			t = t->next;										
		}

	cout << endl;
	fout.close();

}
