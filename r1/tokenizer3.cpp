#include <iostream>
#include <string>
#include <iterator>
#include <boost/tokenizer.hpp>

struct tag_separator {
	void reset () {}

	template<typename Iterator, typename Token>
	bool operator()(Iterator& i, Iterator end, Token& tok)
	{
		tok = Token();
		if (i == end)
			return false;

		if (*i == '<') {
			for ( ; i != end && *i != '>'; ++i) {
				tok += *i;
			}
			if (i == end)
				return false;

			tok += *i++;
			return true;
		} else {
			for ( ; i != end && *i != '<'; ++i) {
				tok += *i;
			}
			return true;
		}
	}
};

int main(void)
{
	std::cin.unsetf(std::ios_base::skipws);
	std::string str( (std::istream_iterator<char>(std::cin)), std::istream_iterator<char>());
	boost::tokenizer<tag_separator> tokens(str);

	for (auto it = tokens.begin(); it != tokens.end(); ++it) {
		std::cout << "Token: " << *it << std::endl;
	}

	return 0;
}
