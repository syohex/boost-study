#include <iostream>
#include <boost/numeric/interval.hpp>

template<typename T, typename P>
std::ostream& operator<<(std::ostream& os, const boost::numeric::interval<T,P>& itv)
{
	return os << "[from " << itv.lower()
		  << " to " << itv.upper() << "]";
}

int main(void)
{
	boost::numeric::interval<int> x(0, 100);
	boost::numeric::interval<int> y(-20, 55);

	boost::numeric::interval<int> z = x*y;
	std::cout << x << " * " << y << " = " << z << std::endl;

	std::cout << boost::numeric::intersect(x, y) << std::endl;
	return 0;
}
