#include <iostream>
#include <boost/array.hpp>

int main()
{
	boost::array<int, 5> ar = {1, 5, 10, 50, 100};

	for (int i = 0; i != 5; ++i)
		std::cout << ar[i] << ' ';

	std::cout << std::endl;

	return 0;
}
