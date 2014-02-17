#include <iostream>
#include <boost/dynamic_bitset.hpp>

int main(void)
{
	boost::dynamic_bitset<> a(10);
	boost::dynamic_bitset<> b(10);

	a[0] = a[3] = a[5] = 1;
	b[1] = b[3] = b[8] = b[9] = 1;

	boost::dynamic_bitset<> c = a & b;
	boost::dynamic_bitset<> d = a ^ b;
	boost::dynamic_bitset<> e = a << 3;
	
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << c << std::endl;
	std::cout << d << std::endl;
	std::cout << e << std::endl;

	std::cout << (c.is_subset_of(e) ? "yes" : "no") << std::endl;

	return 0;
}
