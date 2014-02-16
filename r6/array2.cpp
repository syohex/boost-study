#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <set>
#include <string>
#include <boost/array.hpp>

struct println {
	template<typename T>
	void operator()(const T& t) const {
		std::cout << t << ", ";
	}
};

template<class Cont>
void print_all(const Cont& c)
{
	std::for_each(c.begin(), c.end(), println());
	std::cout << std::endl;
}

int main(void)
{
	std::vector<double> v;
	v.push_back(1.2);
	v.push_back(3.4);

	std::list<int> lst;
	lst.push_back(-5);
	lst.push_back(-6);

	std::set<char> s;
	s.insert('X');
	s.insert('Y');

	boost::array<std::string, 2> a = {"aaa", "bbb"};

	print_all(v);
	print_all(lst);
	print_all(s);
	print_all(a);
	
	return 0;
}
