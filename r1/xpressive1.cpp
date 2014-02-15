#include <iostream>
#include <boost/xpressive/xpressive.hpp>

int main()
{
	boost::xpressive::cregex re = boost::xpressive::cregex::compile("\\d+(m|cm|mm)");

	if (boost::xpressive::regex_match("129cm", re))
		std::cout << "Match: 129cm" << std::endl;

	if (boost::xpressive::regex_match("42km", re))
		std::cout << "Match: 42km" << std::endl;

	if (boost::xpressive::regex_match("6mm", re))
		std::cout << "Match: 6mm" << std::endl;

	if (boost::xpressive::regex_match("10c", re))
		std::cout << "Match: 10c" << std::endl;

	if (boost::xpressive::regex_match("10c", re,
					  boost::xpressive::regex_constants::match_partial))
		std::cout << "10c - partial" << std::endl;

	return 0;
}
