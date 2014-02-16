#include <iostream>
#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>

static void handler(const boost::system::error_code& e)
{
	if (e)
		std::cout << "[3] Cancel!!" << std::endl;
	else
		std::cout << "[3] Take 3 seconds" << std::endl;
}

static void cancel(const boost::system::error_code& e,
		   boost::asio::deadline_timer *t)
{
	t->cancel();

	if (e)
		std::cout << "[2] Cancel!!" << std::endl;
	else
		std::cout << "[2] Take 2 second" << std::endl;
}

int main(void)
{
	boost::asio::io_service io;

	boost::asio::deadline_timer t1(io, boost::posix_time::seconds(3));
	t1.async_wait(&handler);

	boost::asio::deadline_timer t2(io, boost::posix_time::seconds(2));
	t2.async_wait(boost::bind(&cancel, _1, &t1));

	io.run();
	return 0;
}
