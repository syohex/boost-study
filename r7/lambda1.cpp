#include <iostream>
#include <vector>
#include <algorithm>
#include <boost/lambda/lambda.hpp>

int main(void)
{
	using namespace boost::lambda;

	int init_v[] = {-25, -15, 0, 25, 15};
	std::vector<int> v(init_v, init_v + 5);

	std::for_each(v.begin(), v.end(), (_1 += 10));

	std::for_each(v.begin(), v.end(), (std::cout << _1 << ' '));
	std::cout << std::endl;

	int sq_sum = 0;
	std::for_each(v.begin(), v.end(), (sq_sum += _1 * _1));
	std::cout << "Squeare Sum = " << sq_sum << std::endl;

	std::vector<int>::iterator it = std::adjacent_find(v.begin(), v.end(), (_1 > _2));
	std::cout << "skew_pair: " << *it << std::endl;

	std::replace_if(v.begin(), v.end(), (_1 < 0 || 100 < _1), 0);
	std::for_each(v.begin(), v.end(), (std::cout << _1 << ' '));
	std::cout << std::endl;

	return 0;
}
