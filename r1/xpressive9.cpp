#include <iostream>
#include <string>
#include <boost/xpressive/xpressive.hpp>
#include <boost/xpressive/traits/null_regex_traits.hpp>

int main(void)
{
	boost::xpressive::null_regex_traits<int> nul;
	boost::xpressive::basic_regex<int*> onedigit
		= boost::xpressive::imbue(nul)( +boost::xpressive::range(1, 9));

	int array[] = {123, 4, 5, 67, -8, 9};

	boost::xpressive::regex_iterator<int*> it(&array[0], &array[6], onedigit);
	boost::xpressive::regex_iterator<int*> end;

	for (; it != end; ++it) {
		std::cout << "[" << it->position() << ","
			  << it->position()+it->length() << ")"
			  << std::endl;
	}
	return 0;
}
