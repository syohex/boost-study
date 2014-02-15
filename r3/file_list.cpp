#include <iostream>
#include <boost/filesystem.hpp>

int main(int argc, char *argv[])
{
	boost::filesystem::path dir = (argc <= 1 ?
				       boost::filesystem::current_path()
				       : boost::filesystem::path(argv[1]));

	std::cout << boost::filesystem3::complete(dir).string()
		  << " content " << std::endl;

	boost::filesystem::directory_iterator it(dir);
	boost::filesystem::directory_iterator end;

	for (; it != end; ++it) {
		boost::filesystem::path p = *it;

		if (boost::filesystem::is_directory(p))
			std::cout << "[" << p.leaf() << "]" << std::endl;
		else
			std::cout << p.leaf() << std::endl;
	}

	return 0;
}
