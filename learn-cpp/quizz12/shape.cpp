#include "shape.h"

std::ostream& Shape::print (std::ostream& out) const
{
	out << "Shape";
	return out;
}


std::ostream& operator<< (std::ostream& out, const Shape& shape)
{
	return shape.print (out);
}
