#include "Building.h"
#include <iostream>

using namespace std;

Building::Building(int num) : numApart{ num } {}

Building::Building(const Building& other) : numApart(other.numApart) {
    apartments = other.apartments;
}

void Building::addApartment(const Apartment& apartment) {
    apartments.push_back(apartment);
}

void Building::removeApartment(int index) {
    if (index >= 0 && index < apartments.size()) {
        apartments.erase(apartments.begin() + index);
    }
    else {
        cout << "Such an apartment does not exist." << endl;
    }
}

void Building::showApartment() const {
    if (apartments.empty()) {
        cout << "Apartments are empty." << endl;
    }
    else {
        for (auto& apartment : apartments) {
           apartment.showResidents();
           
        }
    }
}

Building::~Building() {

}