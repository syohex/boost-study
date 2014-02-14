#include <iostream>
#include <string>
#include <boost/tokenizer.hpp>

int main()
{
	std::string str;

	while (std::getline(std::cin, str)) {
		boost::escaped_list_separator<char> esc;
		boost::tokenizer<boost::escaped_list_separator<char>> tokens(str, esc);

		for (auto it = tokens.begin(); it != tokens.end(); ++it) {
			std::cout << "[" << *it << "]   " ;
		}
		std::cout << std::endl;
	}

	return 0;
}
