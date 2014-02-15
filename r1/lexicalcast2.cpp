#include <iostream>
#include <fstream>
#include <string>
#include <boost/lexical_cast.hpp>

struct Date {
	int month_;
	int date_;

	explicit Date(int m, int d) : month_(m), date_(d) {}
};

std::ostream& operator<<(std::ostream& os, const Date& d)
{
	return os << d.month_ << '-' << d.date_;
}

int main(void)
{
	Date today(12, 4);

	std::string filename = "diary-" + boost::lexical_cast<std::string>(today);
	std::ofstream fout(filename.c_str());

	fout << "Today is very funny day!!" << std::endl;
	return 0;
}
