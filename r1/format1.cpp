#include <iostream>
#include <boost/format.hpp>

int main(void)
{
	double x = 1.23, y = 4.56;
	std::cout << boost::format("(%1%, %2%)") % x % y << std::endl;
	return 0;
}
