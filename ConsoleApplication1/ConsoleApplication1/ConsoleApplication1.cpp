#include "Person.h"
#include "Apartment.h"
#include "Building.h"
#include <iostream>
using namespace std;


int main()
{
	Person person("N");
	cout << person.info() << endl;
	Apartment apps(10);

	apps.addResident(person);
	apps.showResidents();
	apps.removeResident(0);
	apps.showResidents();


	Person personM("M");
	Person persoV("V");
	Apartment apps2(10);
	Apartment apps3(10);
	Building building(10);
	apps.addResident(personM);
	apps.addResident(persoV);
	building.addApartment(apps);
	building.addApartment(apps2);
	building.addApartment(apps3);
	building.showApartment();
	return 0;
}