#include <iostream>
#include <ctime>
#include <algorithm>
#include <boost/random.hpp>

int main(void)
{
	const int car_arriaval_per_minutes = 3;
	const int capacity_per_minute = 3;

	boost::variate_generator< boost::mt19937, boost::poisson_distribution<> >
		rand(boost::mt19937(static_cast<uint32_t>(time(0))),
		     boost::poisson_distribution<int>(car_arriaval_per_minutes));

	int car = 0;
	for (int m = 0; m < 30; ++m) {
		car += rand();
		car = std::max(car - capacity_per_minute, 0);
		for (int i = 0; i < car; ++i) {
			std::cout << "凸";
		}
		std::cout << std::endl;
	}
	return 0;
}
