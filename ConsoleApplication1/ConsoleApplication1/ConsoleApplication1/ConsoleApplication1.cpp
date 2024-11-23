#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

class Reservoir {
    string name;
    int width;
    int length;
    int maxDepth;
    string type;

public:
    Reservoir() 
    {
        name = "Unknown";
        width = 0;
        length = 0;
        maxDepth = 0;
        type = "Unknown";
    }

    Reservoir(string n, int w, int l, int d, string t) {
        name = n;
        width = w;
        length = l;
        maxDepth = d;
        type = t;
    }

    Reservoir(const Reservoir& other) {
        name = other.name;
        width = other.width;
        length = other.length;
        maxDepth = other.maxDepth;
        type = other.type;
    }
    void setName(string n) { name = n; }
    void setWidth(int w) { width = w; }
    void setLength(int l) { length = l; }
    void setMaxDepth(int d) { maxDepth = d; }
    void setType(string t) { type = t; }

    string getName() const { return name; }
    int getWidth() const { return width; }
    int getLength() const { return length; }
    int getMaxDepth() const { return maxDepth; }
    string getType() const { return type; }
    int calculateVolume() {
        return width * length * maxDepth;
    }

    int calculateSurfaceArea() {
        return width * length;
    }

    bool isSameType(Reservoir& other) {
        return type == other.type;
    }

    bool hasLargerSurfaceArea(Reservoir& other) {
        if (isSameType(other)) {
            return calculateSurfaceArea() > other.calculateSurfaceArea();
        }
        return false;
    }

    void display() {
        cout << "Name: " << name << endl;
        cout << "Type: " << type << endl;
        cout << "Width: " << width << " m" << endl;
        cout << "Length: " << length << " m" << endl;
        cout << "Max Depth: " << maxDepth << " m" << endl;
        cout << "Volume: " << calculateVolume() << " cubic meters" << endl;
        cout << "Surface Area: " << calculateSurfaceArea() << " square meters" << endl;
    }
    void writeToFile(ofstream& file) {
        file << "Name: " << name << endl;
        file << "Type: " << type << endl;
        file << "Width: " << width << " m" << endl;
        file << "Length: " << length << " m" << endl;
        file << "Max Depth: " << maxDepth << " m" << endl;
        file << "Volume: " << calculateVolume() << " cubic meters" << endl;
        file << "Surface Area: " << calculateSurfaceArea() << " square meters" << endl;
        file << "-------------------" << endl;
    }

};

int main() {
    vector<Reservoir> reservoirs;

    Reservoir r1("Lake Victoria", 5000, 7000, 80, "Lake");
    Reservoir r2("Baltic Sea", 100000, 300000, 200, "Sea");

    reservoirs.push_back(r1);
    reservoirs.push_back(r2);

    for (int i = 0; i < reservoirs.size(); i++) {
        reservoirs[i].display();
        cout << "-------------------" << endl;
    }

    ofstream file("reservoirs.txt");
    if (file.is_open()) {
        for (int i = 0; i < reservoirs.size(); i++) {
            reservoirs[i].writeToFile(file);
        }
        file.close();
        cout << "Data written to reservoirs.txt" << endl;
    }
    else {
        cout << "Error opening file!" << endl;
    }

    return 0;
}
