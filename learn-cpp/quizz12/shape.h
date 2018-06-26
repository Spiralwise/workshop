#ifndef _SHAPE_H
#define _SHAPE_H
#include <iostream>

class Shape
{
	virtual std::ostream& print (std::ostream&) const;

public:
	virtual ~Shape () { }

	friend std::ostream& operator<< (std::ostream&, const Shape&);
};

#endif // _SHAPE_H
