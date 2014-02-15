#include <iostream>
#include <boost/lexical_cast.hpp>

int main(int argc, char *argv[])
{
	if (argc <= 1)
		return -1;

	try {
		int N = boost::lexical_cast<int>(argv[1]);
		for (int i = 0; i < N; ++i) {
			std::cout << "Repeat: " << i << std::endl;
		}
	} catch(const boost::bad_lexical_cast& e) {
		std::cout << "Please input numeric number" << std::endl;
		return -1;
	}

	return 0;
}
