#include <iostream>
#include <string>
#include <vector>
#include <boost/algorithm/string.hpp>

int main(void)
{
	std::string s("Hello Hello Hello");

	boost::algorithm::replace_last(s, "Hello", "Apple");
	std::cout << s << std::endl;

	std::cout << boost::algorithm::erase_all_copy(s, "Hello") << std::endl;

	std::cout << boost::algorithm::replace_first_copy(s, "Hello", "GoodBye")
		  << std::endl;
	return 0;
}
