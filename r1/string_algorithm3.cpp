#include <iostream>
#include <string>
#include <vector>
#include <boost/algorithm/string.hpp>

int main(void)
{
	for (;;) {
		std::cout << "Input number >> ";

		std::string str;
		if (!std::getline(std::cin, str))
			break;

		boost::algorithm::trim(str);

		if (boost::algorithm::all(str, boost::algorithm::is_digit())
		    && boost::algorithm::ends_with(str, "00"))
			std::cout << str << " is multiple of 100" << std::endl;
	}

	return 0;
}
