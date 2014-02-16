#include <iostream>
#include <boost/bind.hpp>

static void test(const char *c1, const char *c2,
		 const char *c3, const char *c4)
{
	std::cout << c1 << ' ' << c2 << ' '
		  << c3 << ' ' << c4 << std::endl;
}

int main(void)
{
	boost::bind(&test, _1, _2, "three", "four")("one", "two");
	boost::bind(&test, "one", _1, "three", _2)("two", "three");

	boost::bind(&test, _4, _3, _2, _1)("1", "2", "3", "4");

	boost::bind(&test, _1, _1, "foo", _2)("bar", "baz");

	boost::bind(&test, _3, _3, _3, _3)("foo", "bar", "baz");
	return 0;
}
