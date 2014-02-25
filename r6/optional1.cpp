#include <iostream>
#include <boost/optional.hpp>

boost::optional<int> str_find(const char *str, char ch)
{
	for (int i = 0; str[i] != '\0'; ++i) {
		if (str[i] == ch) {
			return i;
		}
	}

	return boost::none;
}

int main(void)
{
	const char *strs[] = {"Good", "Bye", "Hello", "World"};

	for (int i = 0; i < 4; ++i) {
		std::cout << strs[i] << ": ";

		boost::optional<int> j = str_find(strs[i], 'o');
		if (j) {
			std::cout << *j << std::endl;
		} else {
			std::cout << "Not Found!!" << std::endl;
		}
	}
	return 0;
}
