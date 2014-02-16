#include <iostream>
#include <functional>
#include <cmath>
#include <boost/bind.hpp>

int main(void)
{
	double x = 3.0, y = 4.0;

	std::cout <<
		boost::bind(&sqrt,
			boost::bind(std::plus<double>(),
				boost::bind(std::multiplies<double>(), _1, _1),
				boost::bind(std::multiplies<double>(), _2, _2)
				))(x, y)
		<< std::endl;

	return 0;
}
