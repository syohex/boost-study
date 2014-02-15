#include <iostream>
#include <boost/xpressive/xpressive.hpp>

int main(void)
{
	boost::xpressive::cregex re = +boost::xpressive::_d >> (boost::xpressive::as_xpr("m")|"cm"|"mm");

	if (boost::xpressive::regex_match("129cm", re))
		std::cout << "129cm - OK" << std::endl;

	if (boost::xpressive::regex_match("42km", re))
		std::cout << "42km - OK" << std::endl;

	if (boost::xpressive::regex_match("33mm", re))
		std::cout << "33mm - OK" << std::endl;

	if (boost::xpressive::regex_match("10c", re))
		std::cout << "10c - OK" << std::endl;

	return 0;
}
