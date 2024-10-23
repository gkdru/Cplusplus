#include <iostream>
#include "Fraction.h"
using namespace std;


Fraction::Fraction():Fraction(1,1){}

Fraction::Fraction(int num, int den): numenator{num}, denominator{den}{}


int Fraction::getNum()const 
{
	return this->numenator;
}
int Fraction::getDen()const {
	return this->denominator;
}
void Fraction::setNum(int num) {
	this->numenator = num;
}
void Fraction::setDen(int num) {
	this->denominator = num;
}


static const Fraction add(const Fraction& f1, const Fraction& f2) {
	return Fraction((f1.getNum() * f2.getDen() + f2.getNum() * f1.getDen()), f1.getDen() * f2.getDen());
}

const Fraction operator+(const Fraction& f1, const Fraction& f2)
{
	return add(f1, f2);
}


static const Fraction substract(const Fraction& f1, const Fraction& f2) {
	return Fraction((f1.getNum() * f2.getDen() - f2.getNum() * f1.getDen()), f1.getDen() * f2.getDen());
}

const Fraction operator-(const Fraction& f1, const Fraction& f2)
{
	return substract(f1, f2);
}


static const Fraction mult(const Fraction& f1, const Fraction& f2) {
	return Fraction((f1.getNum() * f2.getNum()), f1.getDen() * f2.getDen());
}

const Fraction operator*(const Fraction& f1, const Fraction& f2)
{
	return mult(f1, f2);
}


static const Fraction divide(const Fraction& f1, const Fraction& f2) {
	return Fraction((f1.getNum() * f2.getDen()), f1.getDen() * f2.getNum());
}

const Fraction operator/(const Fraction& f1, const Fraction& f2)
{
	return divide(f1, f2);
}

void Fraction::display()const
{
	cout << numenator <<"/" << denominator << endl;
}