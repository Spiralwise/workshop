#include <iostream>
#include <string>


class Ball
{
	std::string m_color;
	double      m_radius;

public:
	Ball (const double radius)
	{
		m_color = "Black";
		m_radius = radius;
	}

	Ball (const std::string &color = "Black", const double radius = 10.0)
	{
		m_color = color;
		m_radius = radius;
	}

	void Print ()
	{
		std::cout << "Color: " << m_color;
		std::cout << "\t[r=" << m_radius << "]" << std::endl;
	}
};


int main()
{
    Ball def;
    def.Print();

	Ball blue("Blue");
	blue.Print();

	Ball twenty(20.0);
	twenty.Print();

	Ball blueTwenty("Blue", 20.0);
	blueTwenty.Print();

    return 0;
}
