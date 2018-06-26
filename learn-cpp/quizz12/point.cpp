#include "point.h"

Point::Point (int x, int y, int z)
	: m_x (x)
	, m_y (y)
	, m_z (z)
{
	// Empty
}


std::ostream& operator<< (std::ostream& out, const Point& point)
{
	out << "Point(" << point.m_x << ", " << point.m_y << ", " << point.m_z << ")";
	return out;
}
