//Rational.cpp
#include"Rational.h"
#include<sstream>
#include<math.h>
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

Rational Rational::operator--(int garbage)
{
	Rational result = *this;
	numerator -= denominator;
	Reduce();
	return result;
}

const Rational operator* (const long lValue, const Rational & rValue)
{
	Rational lValueConverted = Rational(lValue);
	return lValueConverted * rValue;
}


istream &operator>>(istream& in, Rational& Fraction)
{
	int newNumerator = 0; int newDenominator = 1;
	in >> newNumerator;
	in.get();
	in >> newDenominator;
	Rational newRational(newNumerator, newDenominator);
	Fraction = newRational;

	return in;
}

const Rational Rational::operator^(const Rational& rValue) const
{
	Rational result = *this;

	result = result ^ rValue.getNumerator();
	result.numerator = std::pow(result.getNumerator(), (1.0 / rValue.getDenominator())) * 1000000000000000;
	result.denominator = std::pow(result.getDenominator(), (1.0 / rValue.getDenominator())) * 1000000000000000;
	
	result.Reduce();
	return result;
}





//JME Stuff

bool Rational::operator>(const Rational& rValue) const
{
	bool result = false;
	long LCM = LeastCommonMultiple(denominator, rValue.getDenominator());
	if (numerator*(LCM / denominator) > rValue.getNumerator()*(LCM / rValue.getDenominator()))
	{
		result = true;
	}
	return result;
}

bool Rational::operator<=(const Rational& rValue) const
{
	return !(*this > rValue);
}

const Rational Rational::operator*(const Rational& rValue) const
{
	Rational result((numerator*rValue.getNumerator()), (denominator*rValue.getDenominator()));
	result.Reduce();
	return result;
}

const Rational Rational::operator/(const Rational& rValue) const
{
	Rational reciprocal(rValue.getDenominator(), rValue.getNumerator());
	Rational result = *this * reciprocal;
	result.Reduce();
	return result;
}

const Rational Rational::operator^(long rValue) const
{
	Rational result(numerator*rValue, denominator*rValue);
	result.Reduce();
	return result;
}

Rational& Rational::operator-= (const Rational& rValue)
{
	*this = *this - rValue;
	Reduce();
	return *this;
}

Rational& Rational::operator/= (const Rational& rValue)
{
	*this = *this / rValue;
	Reduce();
	return *this;
}
Rational& Rational::operator--()
{
	numerator -= denominator;
	Reduce();
	return *this;
}

const Rational operator- (const long lValue, const Rational & rValue)
{
	Rational LValue(lValue);

	return (LValue - rValue);
}

const Rational operator/ (const long lValue, const Rational & rValue)
{
	Rational LValue(lValue);

	return (LValue / rValue);
}