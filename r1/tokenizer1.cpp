#include <iostream>
#include <string>
#include <boost/tokenizer.hpp>

int main()
{
	std::string input = "This is a pen.";

	boost::char_separator<char> sep(" \t\n");
	boost::tokenizer<boost::char_separator<char>> tokens(input, sep);

	boost::tokenizer<boost::char_separator<char>>::iterator it;
	for (it = tokens.begin(); it != tokens.end(); ++it) {
		std::cout << "Token: " << *it << std::endl;
	}

	return 0;
}
