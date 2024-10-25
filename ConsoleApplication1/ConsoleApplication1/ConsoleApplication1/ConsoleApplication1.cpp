#include <iostream> 
using namespace std;
static int counter{ 0 };


class String
{
    char* value;
    int size;


public:
    String() : size{ 80 }, value{ new char[size] } {
        cout << "enter text" << endl;
        cin >> value;
        cout << "Object created with CIN.Len :" << this->size << endl << this->value << endl;
        counter++;

    };

    String(int size, const char* value) : size{ size + 1 }, value{ new char[size] } {
        if (value) {
            strcpy_s(this->value, this->size, value);
            counter++;
        }
        cout << "Custom len:" << this->size << endl << this->value << endl;
    }
    String(const char* value) : size{ int(strlen(value)) + 1 }, value{ new char[size] } {
        if (value) {

            strcpy_s(this->value, size, value);
            counter++;
        }
        cout << "Str from user. " << "Len:" << this->size << endl << this->value << endl;
    }
    String(const String& object) : size{ object.size }, value{ new char[size] } {
        strcpy_s(this->value, object.size, object.value);
        cout << "ojbect copy" << "Len:" << this->size << endl << this->value << endl;
        counter++;
    }

    char* getValue() {
        return this->value;
    }
    String& setValue(const char* value) {
        strcpy_s(this->value, strlen(value), value);
        return *this;
    }
    void getCounter()
    {
        cout << "Counter of objects:" << counter << endl;
    }

};


int main() {
    String a;

    const char* s{ "aaa" };
    String b{ 3, s };

    const char* ss{ "qwe" };
    String c(ss);
    String d(c);

    c.getCounter();
    return 0;
}