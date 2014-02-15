#include <iostream>
#include <string>
#include <boost/xpressive/xpressive.hpp>

int main()
{
	boost::xpressive::sregex re = boost::xpressive::sregex::compile("<[^>]+>");
	std::string str("This is a <em>Vim</em>.");

	boost::xpressive::sregex_iterator it(str.begin(), str.end(), re);
	boost::xpressive::sregex_iterator end;

	for ( ; it != end; ++it)
		std::cout << it->position() << ": " << it->str() << std::endl;

	return 0;
}
