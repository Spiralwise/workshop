#include <cmath>
#include <cstdint>
#include <iostream>

using int16 = std::int16_t;
using int8  = std::int8_t;


class FixedPoint2
{
	int16 m_base;
	int8  m_decimal;

public:
	FixedPoint2 (int16_t a, int8_t b)
		: m_base (a)
		, m_decimal (b)
	{
		if (m_base < 0 && m_decimal > 0)
			m_decimal = -m_decimal;
		else if (m_base > 0 && m_decimal < 0)
			m_base = -m_base;
	}

	FixedPoint2 (double a)
	{
		m_base = static_cast<int> (a);
		m_decimal = static_cast<int> (round ((a - m_base) * 100));
	}

	operator double () const
	{
		return m_base + m_decimal / 100.0;
	}

	bool operator== (const FixedPoint2& that)
	{
		return m_base == that.m_base && m_decimal == that.m_decimal;
	}

	friend FixedPoint2  operator+ (const FixedPoint2&, const FixedPoint2&);
	friend FixedPoint2  operator- (const FixedPoint2&);
	friend std::ostream& operator<< (std::ostream&, FixedPoint2&);
	friend std::istream& operator>> (std::istream&, FixedPoint2&);
};


FixedPoint2 operator+ (const FixedPoint2& a, const FixedPoint2& b)
{
	double buffer = static_cast<double> (a) + static_cast<double> (b);
	return FixedPoint2 (buffer);
}


FixedPoint2 operator- (const FixedPoint2& a)
{
	return FixedPoint2 (-a.m_base, -a.m_decimal);
}


std::ostream& operator<< (std::ostream& out, FixedPoint2& f)
{
	out << static_cast<double> (f);
	return out;
}


std::istream& operator>> (std::istream& in, FixedPoint2& f)
{
	double buffer;
	in >> buffer;
	f = FixedPoint2 (buffer);
	return in;
}


void TestB ()
{
	FixedPoint2 a(34, 56);
	std::cout << a << '\n';

	FixedPoint2 b(-2, 8);
	std::cout << b << '\n';

	FixedPoint2 c(2, -8);
	std::cout << c << '\n';

	FixedPoint2 d(-2, -8);
	std::cout << d << '\n';

	FixedPoint2 e(0, -5);
	std::cout << e << '\n';

	std::cout << static_cast<double>(e) << '\n';
}


void TestC ()
{
	FixedPoint2 a(0.01);
	std::cout << a << '\n';

	FixedPoint2 b(-0.01);
	std::cout << b << '\n';

	FixedPoint2 c(5.01); // stored as 5.0099999... so we'll need to round this
	std::cout << c << '\n';

	FixedPoint2 d(-5.01); // stored as -5.0099999... so we'll need to round this
	std::cout << d << '\n';
}


void testAddition()
{
	// h/t to reader Sharjeel Safdar for this function
	std::cout << std::boolalpha;
	std::cout << (FixedPoint2(0.75) + FixedPoint2(1.23) == FixedPoint2(1.98)) << '\n'; // both positive, no decimal overflow
	std::cout << (FixedPoint2(0.75) + FixedPoint2(1.50) == FixedPoint2(2.25)) << '\n'; // both positive, with decimal overflow
	std::cout << (FixedPoint2(-0.75) + FixedPoint2(-1.23) == FixedPoint2(-1.98)) << '\n'; // both negative, no decimal overflow
	std::cout << (FixedPoint2(-0.75) + FixedPoint2(-1.50) == FixedPoint2(-2.25)) << '\n'; // both negative, with decimal overflow
	std::cout << (FixedPoint2(0.75) + FixedPoint2(-1.23) == FixedPoint2(-0.48)) << '\n'; // second negative, no decimal overflow
	std::cout << (FixedPoint2(0.75) + FixedPoint2(-1.50) == FixedPoint2(-0.75)) << '\n'; // second negative, possible decimal overflow
	std::cout << (FixedPoint2(-0.75) + FixedPoint2(1.23) == FixedPoint2(0.48)) << '\n'; // first negative, no decimal overflow
	std::cout << (FixedPoint2(-0.75) + FixedPoint2(1.50) == FixedPoint2(0.75)) << '\n'; // first negative, possible decimal overflow
}


void TestD ()
{
	testAddition();

	FixedPoint2 a(-0.48);
	std::cout << a << '\n';

	std::cout << -a << '\n';

	std::cout << "Enter a number: "; // enter 5.678
	std::cin >> a;

	std::cout << "You entered: " << a << '\n';
}


int main()
{
	TestD();

	return 0;
}
