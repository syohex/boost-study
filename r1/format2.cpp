#include <iostream>
#include <boost/format.hpp>

int main(void)
{
	int iX, iY;

	std::cout << "Please input number: ";
	std::cin >> iX;

	std::cout << "Please input second number: ";
	std::cin >> iY;

	std::cout << boost::format("%d + %d = %d") % iX % iY % (iX+iY) << std::endl;
	std::cout << boost::format("%d - %d = %d") % iX % iY % (iX-iY) << std::endl;

	std::cout << "Octal representation: " << std::endl
		  << boost::format("%o + %o = %o") % iX % iY % (iX+iY) << std::endl;

	std::cout << "Hexical representation: " << std::endl
		  << boost::format("%x + %x = %x") % iX % iY % (iX+iY) << std::endl;
	return 0;
}
