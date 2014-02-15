#include <iostream>
#include <boost/date_time/gregorian/gregorian.hpp>

int main(void)
{
	boost::gregorian::nth_day_of_the_week_in_month
		mothers_day_generator(boost::gregorian::nkday::second, boost::gregorian::Sunday, 5);

	for (boost::gregorian::greg_year year = 2003; year <= 2010; year = year + 1) {
		boost::gregorian::date mday = mothers_day_generator.get_date(year);

		std::cout << year << "'s mother's day is May "
			  << mday.day() << "th" << std::endl;
	}
	return 0;
}
