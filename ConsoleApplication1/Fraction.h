#pragma once
#include <iostream>
using namespace std;

class Fraction
{
	int numenator;
	int denominator;


public:
	Fraction();
	Fraction(int num, int den);
	int getNum()const;
	void setNum(int num);
	int getDen()const;
	void setDen(int num);

	friend const Fraction operator+(const Fraction& f1, const Fraction& f2);
	friend const Fraction operator-(const Fraction& f1, const Fraction& f2);
	friend const Fraction operator*(const Fraction& f1, const Fraction& f2);
	friend const Fraction operator/(const Fraction& f1, const Fraction& f2);

	void display() const;
};
