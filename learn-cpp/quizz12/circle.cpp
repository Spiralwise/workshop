#include "circle.h"

Circle::Circle (const Point& c, int r)
	: m_center (c)
	, m_radius (r)
{
	// Empty
}


std::ostream& Circle::print (std::ostream& out) const
{
	out << "Circle(" << m_center << ", " << m_radius << ")";
	return out;
}


int Circle::getRadius ()
{
	return m_radius;
}


std::ostream& operator<< (std::ostream& out, const Circle& c)
{
	return c.print (out);
}
