#include <iostream>
using namespace std;
#include "Fraction.h"



int main()
{
	Fraction f(1, 2);
	Fraction f2(2, 4);
	Fraction a = f + f2;
	a.display();
	return 0;
}
