#include <iostream>
#include <cmath>
#include <boost/format.hpp>

int main(void)
{
	std::cout << boost::format("%3% %2% %1%") % "one" % "two" % "three" << std::endl;
	std::cout << boost::format("%1% %3%") % "one" % "two" % "three" << std::endl;
	std::cout << boost::format("%1% %3% %1% %2%") % "one" % "two" % "three" << std::endl;

	std::cout << boost::format("hexical=%1$x decimal=%1$d octal=%1$o") % 15 << std::endl;
	std::cout << boost::format("%.7e") % (atan(1.0)*4) << std::endl;
	return 0;
}
