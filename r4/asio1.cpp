#include <iostream>
#include <string>
#include <boost/asio.hpp>

int main(void)
{
	boost::asio::ip::tcp::iostream s("syohex.org", "http");

	s << "GET /index.html HTTP/1.0\r\n";
	s << "Host: syohex.org\r\n";
	s << "\r\n";
	s << std::flush;

	std::string line;
	while (std::getline(s, line))
		std::cout << line << std::endl;

	return 0;
}
