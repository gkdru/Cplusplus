#include <iostream>

using namespace std;

class Overcoat {
    string type;
    double price;

public:
    Overcoat(string t = "Unknown", double p = 0.0) : type(t), price(p) {}

    bool operator==(const Overcoat& other) const {
        return this->type == other.type;
    }

    Overcoat& operator=(const Overcoat& other) {
        if (this != &other) {
            type = other.type;
            price = other.price;
        }
        return *this;
    }

    bool operator>(const Overcoat& other) const {
        return this->price > other.price;
    }

 
    void display() const {
        cout << "Type: " << type << ", Price: " << price << endl;
    }
};

class Flat {
private:
    double area;
    double price;

public:
    Flat(double a = 0.0, double p = 0.0) : area(a), price(p) {}

    bool operator==(const Flat& other) const {
        return this->area == other.area;
    }
    Flat& operator=(const Flat& other) {
        if (this != &other) {
            area = other.area;
            price = other.price;
        }
        return *this;
    }
    bool operator>(const Flat& other) const {
        return this->price > other.price;
    }

    void display() const {
        cout << "Area: " << area << " sqm, Price: " << price << " USD" << endl;
    }
};




int main() {
    Overcoat coat1("Wool Coat", 150.0);
    Overcoat coat2("Wool Coat", 120.0);
    Overcoat coat3("Leather Coat", 200.0);

    if (coat1 == coat2) {
        cout << "Coat1 and Coat2 are of the same type." << endl;
    }
    else {
        cout << "Coat1 and Coat2 are of different types." << endl;
    }

    coat3 = coat1;
    coat3.display();

    if (coat1 > coat2) {
        cout << "Coat1 is more expensive than Coat2." << endl;
    }
    else {
        cout << "Coat1 is cheaper than or equal to Coat2." << endl;
    }

    Flat flat1(50.0, 100000);
    Flat flat2(50.0, 95000);
    Flat flat3(70.0, 120000.100);

    if (flat1 == flat2) {
        cout << "Flat1 and Flat2 have the same area." << endl;
    }
    else {
        cout << "Flat1 and Flat2 have different areas." << endl;
    }

    flat3 = flat1;
    flat3.display();

    if (flat1 > flat2) {
        cout << "Flat1 is more expensive than Flat2." << endl;
    }
    else {
        cout << "Flat1 is cheaper than or equal to Flat2." << endl;
    }



    return 0;
}