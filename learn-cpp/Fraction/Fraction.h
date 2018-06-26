#ifndef _FRACTION
#define _FRACTION


class Fraction
{
	int m_numerator;
	int m_denominator;

public:
	Fraction (int n=0, int d=1);

	static int gcd (int, int);

	void Print () const;

	friend Fraction operator* (const Fraction&, const Fraction&);
	friend Fraction operator* (const Fraction&, const int);
	friend Fraction operator* (const int, const Fraction&);
};

#endif // _FRACTION
