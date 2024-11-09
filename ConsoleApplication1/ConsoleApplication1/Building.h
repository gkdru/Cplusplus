#pragma once
#include "Apartment.h"
#include <iostream>
using namespace std;

class Building
{
	vector<Apartment> apartments;
	int numApart;
public:
	Building(int num);
	Building(const Building& other);

	~Building();
	void addApartment(const Apartment& apartment);
	void removeApartment(int index);

	void showApartment() const;


};