#include <vector>
#include <boost/algorithm/string.hpp>

int main(void)
{
	std::string s("Orange Orange Orange");

	boost::algorithm::to_upper(boost::algorithm::find_nth(s, "Orange", 1));
	std::cout << s << std::endl;

	std::cout << "<" << boost::algorithm::trim_copy(boost::algorithm::find_head(s, 6))
		  << ">" << std::endl;
	return 0;
}
