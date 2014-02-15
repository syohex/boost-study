#include <iostream>
#include <string>
#include <vector>
#include <boost/algorithm/string.hpp>

int main(void)
{
	std::string message = "This is an apple";

	std::vector<std::string> v;
	boost::algorithm::split(v, message, boost::algorithm::is_space());

	std::cout << boost::algorithm::join(v, "-") << std::endl;
	return 0;
}
