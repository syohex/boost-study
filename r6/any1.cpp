#include <iostream>
#include <string>
#include <boost/any.hpp>

int main(void)
{
	try {
		boost::any a = 100;
		std::cout << boost::any_cast<int>(a) << std::endl;

		a = std::string("Hello World");
		std::cout << boost::any_cast<std::string>(a) << std::endl;

		a = 3.14159;
		std::cout << boost::any_cast<std::string>(a) << std::endl;
	} catch (boost::bad_any_cast& e) {
		std::cout << e.what() << std::endl;
	}

	return 0;
}
