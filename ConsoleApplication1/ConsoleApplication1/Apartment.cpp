#include "Apartment.h"
#include <iostream>
using namespace std;

Apartment::Apartment(int numR) : numResidents{numR}{}

Apartment::Apartment() : numResidents{0} {}

Apartment::Apartment(const Apartment& other) : numResidents(other.numResidents) {
	residents = other.residents;
}


void Apartment::addResident(Person& person)
{
	residents.push_back(person);
}

void Apartment::removeResident(int index)
{
	if(index >= 0 && index < residents.size())
	{
		residents.erase(residents.begin() + index);
	}
	else
	{
		cout << "Such a person does not exist" << endl;
	}
}

void Apartment::showResidents() const
{
	if(residents.empty())
	{
		cout << "Empty residents" << endl;
	}
	for(const auto& person : residents)
	{
		cout << "Resident name:" << person.info() << endl;
	}
}



Apartment::~Apartment() 
{
	
}