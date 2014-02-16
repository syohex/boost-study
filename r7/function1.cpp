#include <iostream>
#include <iomanip>
#include <functional>
#include <string>
#include <boost/bind.hpp>
#include <boost/function.hpp>

bool is_substr_of(const std::string& sub, const std::string& all)
{
	return all.find(sub) != std::string::npos;
}

int main(void)
{
	std::cout << std::boolalpha;

	boost::function<bool (const std::string&, const std::string&)> f;

	f = &is_substr_of;
	std::cout << f("a", "abc") << std::endl;
	std::cout << f("a", "bbb") << std::endl;
	std::cout << f("ccc", "dd") << std::endl;
	std::cout << "------------" << std::endl;

	f = boost::bind(std::less<size_t>(),
			boost::bind(&std::string::length, _1),
			boost::bind(&std::string::length, _2));

	std::cout << f("a", "bbb") << std::endl;
	std::cout << f("a", "abc") << std::endl;
	std::cout << f("ccc", "dd") << std::endl;

	return 0;
}
