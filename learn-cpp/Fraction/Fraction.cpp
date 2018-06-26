#include <iostream>
#include "Fraction.h"


Fraction::Fraction (int n, int d)
	: m_numerator (n)
	, m_denominator (d)
{
	// Empty
}


int Fraction::gcd (int a, int b)
{
	return (b == 0) ? (a > 0 ? a : -a) : gcd (b, a % b);
}


void Fraction::Print () const
{
	std::cout << m_numerator << "/" << m_denominator << std::endl;
}


Fraction operator* (const Fraction &a, const Fraction &b)
{
	int n = a.m_numerator * b.m_numerator;
	int d = a.m_denominator * b.m_denominator;
	int g = Fraction::gcd (n, d);
	return Fraction (n/g, d/g);
}


Fraction operator* (const Fraction &a, const int x)
{
	int n = a.m_numerator * x;
	int g = Fraction::gcd (n, a.m_denominator);
	return Fraction (n/g, a.m_denominator/g);
}


Fraction operator* (const int x, const Fraction &a)
{
	int n = a.m_numerator * x;
	int g = Fraction::gcd (n, a.m_denominator);
	return Fraction (n/g, a.m_denominator/g);
}
