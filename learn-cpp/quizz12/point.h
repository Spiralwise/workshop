#ifndef _POINT_H
#define _POINT_H
#include <iostream>

class Point
{
	int m_x, m_y, m_z;

public:
	Point (int, int, int);

	friend std::ostream& operator<< (std::ostream&, const Point&);
};

#endif // _POINT_H
