#pragma once
#include <iostream>
#include <vector>
#include "Person.h"
using namespace std;

class Apartment
{
	vector<Person> residents;
	int numResidents;

public:
	Apartment(int numR);
	Apartment();
	Apartment(const Apartment& other);
	~Apartment();
	void removeResident(int index);
	void addResident(Person& person);
	void showResidents() const;

};