#include <iostream>
#include <string>
#include <boost/xpressive/xpressive.hpp>

int main(void)
{
	boost::xpressive::sregex re = boost::xpressive::sregex::compile("G\\w+");
	std::string str("Google Japen");

	std::cout << boost::xpressive::regex_replace(str, re, std::string("!!$&!!"))
		  << std::endl;

	return 0;
}
