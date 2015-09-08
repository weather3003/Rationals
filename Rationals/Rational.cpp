//Rational.cpp
#include"Rational.h"
#include<sstream>
Rational::Rational(long NewNumerator, long NewDenominator)
{
	numerator = NewNumerator;
	denominator = NewDenominator;
	Reduce();
}
const Rational& Rational::operator=(const Rational & rValue)
{
	numerator = rValue.numerator;
	denominator = rValue.denominator;
	Reduce();
	return *this;
}
Rational& Rational::operator++()
{
	numerator += denominator;
	Reduce();
	return *this;
}
Rational Rational::operator++(int Garbage)
{
	Rational result = *this;
	numerator += denominator;
	Reduce();
	return result;
}
bool Rational::operator==(const Rational & rValue) const
{
	bool result = true;
	if (numerator != rValue.numerator || denominator != rValue.denominator)
	{
		result = false;
	}
	return result;
}
const Rational Rational::operator+ (const Rational & rValue) const
{
	long lcm = LeastCommonMultiple(rValue.denominator, denominator);
	long resultNumerator = (numerator * (lcm / denominator)) +
		(rValue.numerator * (lcm / rValue.denominator));
	Rational result(resultNumerator, lcm);
	return result;
}
Rational& Rational::operator+= (const Rational & rValue)
{
	*this = *this + rValue;
	Reduce();
	return *this;
}
string Rational::operator()() const
{
	std::stringstream stream;
	stream << numerator << "/" << denominator;
	return stream.str();
}
ostream &operator<<(ostream & out, const Rational & Fraction)
{
	out << Fraction.getNumerator() << "\\" << Fraction.getDenominator();
	return out;
}
long Rational::getNumerator()const
{
	return numerator;
}
long Rational::getDenominator()const
{
	return denominator;
}
long Rational::LeastCommonMultiple(long x, long y) const
{
	bool Continue = true;
	long result = x;
	while (result % y != 0)
	{
		result += x;
	}
	return result;
}
long Rational::GreatestCommonDivisor(long x, long y) const
{
	long remainder = x % y;
	while (remainder != 0)
	{
		x = y;
		y = remainder;
		remainder = x % y;
	}
	return y;
}
void Rational::Reduce()
{
	long GCD = GreatestCommonDivisor(numerator, denominator);
	numerator = numerator / GCD;
	denominator = denominator / GCD;
}

const Rational Rational::operator- (const Rational& rValue) const
{
	long lcm = LeastCommonMultiple(rValue.denominator, denominator);
	long resultNumerator = (numerator * (lcm / denominator)) -
		(rValue.numerator * (lcm / rValue.denominator));
	Rational result(resultNumerator, lcm);
	return result;
}

bool Rational::operator<(const Rational& rValue) const
{
	Rational comparison = *this - rValue;
	return comparison.numerator < 0;
}

bool Rational::operator>=(const Rational& rValue) const
{
	return !(*this < rValue);
}

bool Rational::operator!=(const Rational& rValue) const
{
	return !(*this == rValue);
}

Rational& Rational::operator*= (const Rational& rValue)
{
	*this = *this * rValue;
	Reduce();
	return *this;
}

Rational::operator double() const
{
	double result = numerator / denominator;
	return result;
}