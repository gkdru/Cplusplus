#include <iostream>
#include <cmath>

using namespace std;

class Fraction {
    int gcd(int a, int b) {
        int res = min(a, b);
        while (res > 1) {
            if (a % res == 0 && b % res == 0)
                break;
            res--;
        }
        return res;
    }


    int numerator;
    int denominator;

    void reduce() {
        int nod = gcd(numerator, denominator);
        numerator /= nod;
        denominator /= nod;
        if (denominator < 0) {
            numerator = -numerator;
            denominator = -denominator;
        }
    }

public:
    Fraction(int num = 0, int den = 1) : numerator(num), denominator(den) {
        if (den == 0) {
            throw invalid_argument("Denominator cannot be zero!");
        }
        reduce();
    }

    Fraction operator+(const Fraction& other) const {
        return Fraction(numerator * other.denominator + other.numerator * denominator,
            denominator * other.denominator);
    }

    Fraction operator-(const Fraction& other) const {
        return Fraction(numerator * other.denominator - other.numerator * denominator,
            denominator * other.denominator);
    }

    Fraction operator*(const Fraction& other) const {
        return Fraction(numerator * other.numerator, denominator * other.denominator);
    }

    Fraction operator/(const Fraction& other) const {
        if (other.numerator == 0) {
            throw invalid_argument("Division by zero!");
        }
        return Fraction(numerator * other.denominator, denominator * other.numerator);
    }

    friend ostream& operator<<(ostream& os, const Fraction& f) {
        os << f.numerator << "/" << f.denominator;
        return os;
    }
};

class Complex {
    double real;
    double imag;

public:
    Complex(double r = 0.0, double i = 0.0) : real(r), imag(i) {}

    Complex operator+(const Complex& other) const {
        return Complex(real + other.real, imag + other.imag);
    }

    Complex operator-(const Complex& other) const {
        return Complex(real - other.real, imag - other.imag);
    }

    Complex operator*(const Complex& other) const {
        return Complex(real * other.real - imag * other.imag, real * other.imag + imag * other.real);
    }

    Complex operator/(const Complex& other) const {
        double denominator = other.real * other.real + other.imag * other.imag;
        if (denominator == 0) {
            throw invalid_argument("Division by zero!");
        }
        return Complex((real * other.real + imag * other.imag) / denominator,
            (imag * other.real - real * other.imag) / denominator);
    }


    friend ostream& operator<<(ostream& os, const Complex& c) {
        os << c.real;
        if (c.imag >= 0) {
            os << " + " << c.imag << "i";
        }
        else {
            os << " - " << -c.imag << "i";
        }
        return os;
    }
};

int main() {

        Fraction f1(3, 4);
        Fraction f2(5, 6);

        cout << "f1 = " << f1 << ", f2 = " << f2 << endl;
        cout << "f1 + f2 = " << f1 + f2 << endl;
        cout << "f1 - f2 = " << f1 - f2 << endl;
        cout << "f1 * f2 = " << f1 * f2 << endl;
        cout << "f1 / f2 = " << f1 / f2 << endl;

        Complex c1(3, 4);
        Complex c2(1, -2);

        cout << "c1 = " << c1 << ", c2 = " << c2 << endl;
        cout << "c1 + c2 = " << c1 + c2 << endl;
        cout << "c1 - c2 = " << c1 - c2 << endl;
        cout << "c1 * c2 = " << c1 * c2 << endl;
        cout << "c1 / c2 = " << c1 / c2 << endl;


    return 0;
}
