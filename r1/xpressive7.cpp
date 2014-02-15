#include <iostream>
#include <boost/xpressive/xpressive.hpp>

int main(void)
{
	boost::xpressive::cregex reD = boost::xpressive::cregex::compile("abc|def");
	boost::xpressive::cregex reS = "(" >> reD >> ")";

	std::cout << boost::xpressive::regex_match("abc", reS) << std::endl;
	std::cout << boost::xpressive::regex_match("(def)", reS) << std::endl;
	return 0;
}
