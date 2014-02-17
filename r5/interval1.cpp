#include <iostream>
#include <boost/numeric/interval.hpp>

int main(void)
{
	boost::numeric::interval<int> valid_range(1, 100);

	int x = 0;
	do {
		std::cout << "Input from "
			  << valid_range.lower() << " to "
			  << valid_range.upper() << " number : ";
		std::cin >> x;
	} while (!boost::numeric::in(x, valid_range));

	return 0;
}
