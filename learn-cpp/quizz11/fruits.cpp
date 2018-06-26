#include <iostream>


class Fruit
{
protected:
	std::string m_name;
	std::string m_color;

public:
	Fruit (const std::string& name, const std::string& color)
		: m_name (name)
		, m_color (color)
	{
		// Empty
	}

	const std::string& getName () const
	{
		return m_name;
	}

	const std::string& getColor () const
	{
		return m_color;
	}
};


class Apple : public Fruit
{
public:
	Apple (const std::string& color="green")
		: Fruit ("apple", color)
	{
		// Empty
	}
};


class Banana : public Fruit
{
public:
	Banana (const std::string& color="yellow")
		: Fruit ("color", color)
	{
		// Empty
	}
};


class GrannySmith : public Apple
{
public:
	GrannySmith ()
		: Apple ()
	{
		m_name = "granny smith apple";
	}
};


int main()
{
	Apple a("red");
	Banana b;
	GrannySmith c;

	std::cout << "My " << a.getName() << " is " << a.getColor() << ".\n";
	std::cout << "My " << b.getName() << " is " << b.getColor() << ".\n";
	std::cout << "My " << c.getName() << " is " << c.getColor() << ".\n";

	return 0;
}
