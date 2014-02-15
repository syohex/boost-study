#include <iostream>
#include <string>
#include <boost/regex.hpp>

int main(void)
{
	boost::regex re("<[^>]+>");

	std::string str("This <em>is</em> a <strong>pen</strong>");
	if (boost::regex_search(str, re))
		std::cout << "found" << std::endl;

	std::string::const_iterator it = str.begin(), end = str.end();
	while (it != end) {
		boost::smatch result;

		if (!boost::regex_search(it, end, result, re))
			break;

		std::cout << result.str() << std::endl;
		it = result[0].second;
	}
	
	return 0;
}
