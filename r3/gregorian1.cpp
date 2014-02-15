#include <iostream>
#include <boost/date_time/gregorian/gregorian.hpp>

int main(void)
{
	int year, month, day;

	std::cout << "Input Birth Year: ";
	std::cin >> year;

	std::cout << "Input Birth Month: ";
	std::cin >> month;

	std::cout << "Input Birth Day: ";
	std::cin >> day;

	boost::gregorian::date birthday(year, month, day);
	boost::gregorian::date today = boost::gregorian::day_clock::local_day();

	boost::gregorian::days dd = today - birthday;
	std::cout << "Days from your birthday: " << dd.days() << " days" << std::endl;

	std::cout << "Week day of your birthday: " << birthday.day_of_week()
		  << std::endl;
	return 0;
}
