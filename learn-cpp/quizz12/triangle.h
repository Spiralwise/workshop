#ifndef _TRIANGLE_H
#define _TRIANGLE_H
#include "point.h"
#include "shape.h"

class Triangle : public Shape
{
	Point m_a, m_b, m_c;

	virtual std::ostream& print (std::ostream&) const override;

public:
	Triangle (const Point&, const Point&, const Point&);

	friend std::ostream& operator<< (std::ostream&, const Triangle&);
};

#endif // _TRIANGLE_H
