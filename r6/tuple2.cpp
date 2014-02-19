#include <iostream>
#include <boost/tuple/tuple.hpp>

boost::tuple<int, int, int, double> calc_4(int x, int y)
{
	return boost::make_tuple(x+y, x-y, x*y, double(x)/y);
}

int main(void)
{
	int add, sub, mul;
	double div;

	boost::tie(add, sub, mul, div) = calc_4(3, 2);

	std::cout << "add=" << add << std::endl;
	std::cout << "sub=" << sub << std::endl;
	std::cout << "mul=" << mul << std::endl;
	std::cout << "div=" << div << std::endl;

	return 0;
}
