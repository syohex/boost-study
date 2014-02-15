#include <iostream>
#include <set>
#include <iterator>
#include <boost/date_time/posix_time/posix_time.hpp>

struct Plan {
	std::string name;
	boost::posix_time::time_period time;
};

bool operator<(const Plan& lhs, const Plan& rhs)
{
	return lhs.time < rhs.time;
}

std::ostream& operator<<(std::ostream& os, const Plan& p)
{
	return os << p.name << " : " << p.time;
}

struct conflicts_with {
	boost::posix_time::time_period time;

	conflicts_with(const Plan& p) : time(p.time) {}

	bool operator()(const Plan& rhs) const {
		return !time.intersection(rhs.time).is_null();
	}
};

std::string ask(const std::string& question)
{
	std::string answer;
	std::cout << question << ' ';
	std::getline(std::cin, answer);
	return answer;
}

int main(void)
{
	std::set<Plan> plans;

	while (std::cin) {
		std::string name = ask("Add Plan ? ");
		if (name.empty()) {
			std::copy(plans.begin(), plans.end(),
				  std::ostream_iterator<Plan>(std::cout, "\n"));
			continue;
		}

		std::string start = ask("Plan[" + name + "] start time ?");
		std::string length = ask("How many times you take ?");
		auto beginTime = boost::posix_time::time_from_string(start);
		auto endTime = beginTime + boost::posix_time::duration_from_string(length);

		Plan p = {name, boost::posix_time::time_period(beginTime, endTime)};

		auto it = std::find_if(plans.begin(), plans.end(), conflicts_with(p));
		if (it != plans.end())
			std::cout << "- Plan" << *it << " Duplicated" << std::endl;
		else
			plans.insert(p);
	}

	return 0;
}
