#include "triangle.h"

Triangle::Triangle (const Point& a, const Point& b, const Point& c)
	: m_a (a)
	, m_b (b)
	, m_c (c)
{
	// Empty
}


std::ostream& Triangle::print (std::ostream& out) const
{
	out << "Triangle(" << m_a << ", " <<m_b << ", " << m_c << ")";
	return out;
}


std::ostream& operator<< (std::ostream& out, const Triangle& t)
{
	return t.print (out);
}
