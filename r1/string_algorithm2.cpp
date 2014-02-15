#include <iostream>
#include <string>
#include <vector>
#include <boost/algorithm/string.hpp>

int main(void)
{
	std::vector<std::string> v;

	boost::algorithm::split(v, "abc-def+ghi", boost::algorithm::is_any_of("-+"));
	std::cout << boost::algorithm::join(v, "<>") << std::endl;

	boost::algorithm::split(v, "This    is    a    pen", boost::algorithm::is_space());
	std::cout << boost::algorithm::join(v, "<>") << std::endl;

	boost::algorithm::split(v, "This is a pen",
				boost::algorithm::is_space(),
				boost::algorithm::token_compress_on);
	std::cout << boost::algorithm::join(v, "<>") << std::endl;

	return 0;
}
