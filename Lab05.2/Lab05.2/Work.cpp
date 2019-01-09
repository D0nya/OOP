#include "stdafx.h"
#include "Work.h"

Work::Work() {
	aprice = 20;
	cout << "Enter adress: "; cin >> adress;
	cout << "Enter position: "; cin >> position;
}
Work::Work(string tadress, string tposition, int taward) {
	adress = tadress;
	position = tposition;
}
Work::Work(const Work& temp) : Advt(temp), WTS(temp) {
	adress = temp.adress;
	position = temp.position;
}
//getters
string Work::get_adress() { return adress; }
string Work::get_position() { return position; }
//setters
void Work::set_adress(string tadress) { adress = tadress; }
void Work::set_position(string tposition) { position = tposition; }

void Work::get_info(){
	Advt::get_info();
	cout << "Adress: " << adress << endl << "Position: " << position << endl << "Award: " << get_price() << endl << endl;
}