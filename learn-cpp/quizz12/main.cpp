#include <vector>
#include "circle.h"
#include "triangle.h"


void Test ()
{
	Circle c(Point(1, 2, 3), 7);
    std::cout << c << '\n';

    Triangle t(Point(1, 2, 3), Point(4, 5, 6), Point(7, 8, 9));
    std::cout << t << '\n';
}


int getLargestRadius (const std::vector<Shape*> circles)
{
	int max = 0;
	for (Shape* shape : circles)
	{
		Circle* circle = dynamic_cast<Circle*> (shape);
		if (circle != nullptr && circle->getRadius () > max)
			max = circle->getRadius ();
	}
	return max;
}


int main()
{
	std::vector<Shape*> v;
	v.push_back(new Circle(Point(1, 2, 3), 7));
	v.push_back(new Triangle(Point(1, 2, 3), Point(4, 5, 6), Point(7, 8, 9)));
	v.push_back(new Circle(Point(4, 5, 6), 3));

	std::cout << *v[0] << std::endl;
	std::cout << *v[1] << std::endl;
	std::cout << *v[2] << std::endl;

	std::cout << "The largest radius is: " << getLargestRadius(v) << '\n';

	for (Shape* shape : v)
		delete shape;

    return 0;
}
