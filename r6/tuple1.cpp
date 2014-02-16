#include <iostream>
#include <string>
#include <boost/tuple/tuple.hpp>

int main(void)
{
	boost::tuple<int,std::string,float> t(123, "Hello World", 4.5);

	std::cout << t.get<0>() << t.get<1>() << t.get<2>() << std::endl;

	t.get<2>() *= t.get<0>();
	std::cout << t.get<2>() << std::endl;
	return 0;
}
