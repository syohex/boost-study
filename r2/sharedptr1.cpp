#include <iostream>
#include <boost/shared_ptr.hpp>

class Test {
private:
	char id_;

public:
	Test(char id) : id_(id) {
		std::cout << "Construct " << id << std::endl;
	}

	~Test() {
		std::cout << "Destruct " << id_ << std::endl;
	}

	void say_hello() {
		std::cout << "Hello, I'm " << id_ << std::endl;
	}
};


int main(void)
{
	boost::shared_ptr<Test> ptr0;
	{
		boost::shared_ptr<Test> ptr1(new Test('A'));
		boost::shared_ptr<Test> ptr2(new Test('B'));
		boost::shared_ptr<Test> ptr3(new Test('C'));

		ptr1->say_hello();
		ptr0 = ptr1 = ptr2;
		ptr1->say_hello();
	}

	ptr0->say_hello();
	return 0;
}
