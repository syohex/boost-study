#include <iostream>
#include <string>
#include <boost/xpressive/xpressive.hpp>

int main(void)
{
	boost::xpressive::sregex parens;
	parens = *('(' >> boost::xpressive::by_ref(parens) >> ')');

	std::string line;
	std::cout << "# ";

	while (std::getline(std::cin, line)) {
		if (boost::xpressive::regex_match(line, parens))
			std::cout << "Balanced" << std::endl;
		else
			std::cout << "Not Balanced" << std::endl;
	}

	return 0;
}
