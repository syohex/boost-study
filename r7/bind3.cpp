#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <boost/bind.hpp>

int main(void)
{
	std::vector<std::string> v;

	v.push_back("abcde");
	v.push_back("fghijk");
	v.push_back("");
	v.push_back("opqr");
	v.push_back("xyz");

	std::vector<std::string>::iterator end
		= std::remove_if(v.begin(), v.end(), boost::bind(&std::string::empty, _1));

	std::transform(v.begin(), v.end(), v.begin(), boost::bind(&std::string::substr, _1, 2, 2));

	std::cout << v[0] << ' ' << v[1] << ' ' << v[2] << ' ' << v[3] << std::endl;
	return 0;
}
