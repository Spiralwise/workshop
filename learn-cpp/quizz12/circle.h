#ifndef _CIRCLE_H
#define _CIRCLE_H
#include "point.h"
#include "shape.h"

class Circle : public Shape
{
	Point m_center;
	int   m_radius;

	virtual std::ostream& print (std::ostream&) const override;

public:
	Circle (const Point&, int);

	int getRadius ();

	friend std::ostream& operator<< (std::ostream&, const Circle&);
};

#endif // _CIRCLE_H
