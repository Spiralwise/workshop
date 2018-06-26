#include <cstdint>
#include <iostream>
#include <vector>


class Average
{
	int32_t m_sum = 0;
	int8_t  m_len = 0;

	double getAvg () const
	{
		return static_cast<double> (m_sum) / m_len;
	}

public:
	Average& operator+= (int x)
	{
		m_sum += x;
		++m_len;
		return *this;
	}

	friend std::ostream& operator<< (std::ostream&, const Average&);
};


std::ostream& operator<< (std::ostream& out, const Average& a)
{
	out << a.getAvg ();
	return out;
}


int main()
{
	Average avg;

	avg += 4;
	std::cout << avg << '\n'; // 4 / 1 = 4

	avg += 8;
	std::cout << avg << '\n'; // (4 + 8) / 2 = 6

	avg += 24;
	std::cout << avg << '\n'; // (4 + 8 + 24) / 3 = 12

	avg += -10;
	std::cout << avg << '\n'; // (4 + 8 + 24 - 10) / 4 = 6.5

	(avg += 6) += 10; // 2 calls chained together
	std::cout << avg << '\n'; // (4 + 8 + 24 - 10 + 6 + 10) / 6 = 7

	Average copy = avg;
	std::cout << copy << '\n';

	return 0;
}
