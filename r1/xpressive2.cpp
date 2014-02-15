#include <iostream>
#include <string>
#include <boost/xpressive/xpressive.hpp>

int main(void)
{
	boost::xpressive::sregex re = boost::xpressive::sregex::compile("<[^>]+>");
	std::string str("This is <em>pen</em>.");

	if (boost::xpressive::regex_search(str, re))
		std::cout << "found" << std::endl;

	std::string::const_iterator it = str.begin(), end = str.end();

	while (it != end) {
		boost::xpressive::smatch result;

		if (!boost::xpressive::regex_search(it, end, result, re))
			break;

		std::cout << result.str() << std::endl;
		it = result[0].second;
	}

	return 0;
}
