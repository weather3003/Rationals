#include<iostream>
#include"Rational.h"

using namespace std;

void basicWrite(Rational& left, Rational& right, const Rational(Rational::*functionPtr)(const Rational &rValue) const, string opString);
void basicWrite(Rational& left, Rational& right, bool(Rational::*functionPtr)(const Rational &rValue) const, string opString);

void main()
{
	Rational test1(3,4), test2(642/80), test3;

	cout << "Endter a Rational: " << endl;
	cin >> test3;
	cout << endl << "You entered: " << test3 << endl;

	basicWrite(test1, test2, &(Rational::operator<), " < ");
	basicWrite(test1, test2, &(Rational::operator>=), " >= ");
	basicWrite(test1, test2, &(Rational::operator!=), " != ");
	basicWrite(test1, test2, &(Rational::operator^), " ^ ");
	basicWrite(test1, test2, &(Rational::operator-), " - ");
	cout << endl;
	cout << test3 << " = " << (double)test3 << endl;

}

void basicWrite(Rational& left, Rational& right, const Rational (Rational::*functionPtr)(const Rational &rValue) const, string opString)
{
	cout << left;
	cout << opString;
	cout << right;
	cout << " = ";
	cout << (left.*functionPtr)(right);
	cout << endl;
}

void basicWrite(Rational& left, Rational& right, bool(Rational::*functionPtr)(const Rational &rValue) const, string opString)
{
	cout << left;
	cout << opString;
	cout << right;
	cout << " == ";
	cout << (left.*functionPtr)(right);
	cout << endl;
}