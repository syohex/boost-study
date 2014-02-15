#include <iostream>
#include <boost/date_time/posix_time/posix_time.hpp>

int main(void)
{
	boost::posix_time::ptime now = boost::posix_time::second_clock::local_time();

	std::cout << "Current Time is " << now << std::endl;
	std::cout << "After 100 hours is " << now + boost::posix_time::hours(100) << std::endl;

	auto tomorrow = now.date() + boost::gregorian::date_duration(1);

	boost::posix_time::ptime tomorrow_start(tomorrow, boost::posix_time::hours(8));

	boost::posix_time::time_iterator it(now, boost::posix_time::minutes(15));
	for (; it < tomorrow_start; ++it) {
		std::cout << *it << std::endl;
	}
	return 0;
}
