#include <iostream>
#include <boost/random.hpp>

int main(void)
{
	boost::mt19937 gen;
	boost::uniform_int<> dst(-3, 4);
	boost::variate_generator<boost::mt19937, boost::uniform_int<> >rand(gen, dst);

	for (int i = 0; i < 20; ++i)
		std::cout << rand() << ' ';

	std::cout << std::endl;
	return 0;
}
