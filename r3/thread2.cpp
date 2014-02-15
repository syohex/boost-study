#include <iostream>
#include <string>
#include <boost/thread.hpp>
#include <boost/bind.hpp>

class Urger {
private:
	const char *message_;
	volatile bool end_flag_;
	boost::mutex state_guard_;
	boost::condition_variable state_change_;

public:
	Urger(const char *message) : message_(message), end_flag_(false) {}

	void run() {
		for (;;) {
			boost::mutex::scoped_lock lk(state_guard_);
			if (end_flag_)
				break;

			boost::xtime xt;
			boost::xtime_get(&xt, boost::TIME_UTC);
			xt.sec += 5;

			if (state_change_.timed_wait(lk, xt))
				continue;
			else
				std::cout << std::endl << message_ << std::flush;
		}
	}

	void on_input_was_done() {
		boost::mutex::scoped_lock lk(state_guard_);
		end_flag_ = true;
		state_change_.notify_all();
	}
};

int main(void)
{
	Urger u("Input something >> ");

	boost::thread urger_thread(boost::bind(&Urger::run, &u));

	std::string str;
	std::cout << "Input something too >> ";
	std::getline(std::cin, str);

	u.on_input_was_done();
	urger_thread.join();

	std::cout << "Thank you" << std::endl;
	return 0;
}
