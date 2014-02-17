#include <iostream>
#include <typeinfo>
#include <boost/mpl/sizeof.hpp>
#include <boost/mpl/list.hpp>
#include <boost/mpl/sort.hpp>
#include <boost/mpl/for_each.hpp>

typedef boost::mpl::list<int, char, double, short, void*> TypeList;
typedef boost::mpl::sort<TypeList, boost::mpl::less< boost::mpl::sizeof_<boost::mpl::_1>,
						     boost::mpl::sizeof_<boost::mpl::_2> > >::type SortedTL;

struct {
	template<typename T>
	void operator()(const T&) const {
		std::cout << typeid(T).name() << std::endl;
	}
} print_type;

int main(void)
{
	boost::mpl::for_each<SortedTL>(print_type);
	return 0;
}
