#include <cstdint>
#include <iostream>


class RGBA
{
	std::uint8_t m_red;
	std::uint8_t m_green;
	std::uint8_t m_blue;
	std::uint8_t m_alpha;

public:
	RGBA (std::uint8_t r=0, std::uint8_t g=0, std::uint8_t b=0, std::uint8_t a=255)
		: m_red (r)
		, m_green (g)
		, m_blue (b)
		, m_alpha (a)
	{
		// Empty
	}

	void print ()
	{
		std::cout << "r=" << static_cast<int> (m_red);
		std::cout << " g=" << static_cast<int> (m_green);
		std::cout << " b=" << static_cast<int> (m_blue);
		std::cout << " a=" << static_cast<int> (m_alpha);
	}
};


int main()
{
	RGBA teal(0, 127, 127);
	teal.print();

	return 0;
}
