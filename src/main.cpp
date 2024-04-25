//Made by Neal Wang, Peter Liu, Charles Liu, Eric Du

#include "manager.hpp"
#include "test.hpp"

int main() {
	test test;
	test.run_all_tests();
	manager manager;
	manager.run();

	return 0;
}
