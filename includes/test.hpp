#pragma once

#define _USE_MATH_DEFINES

#include "matrix.hpp"
#include "transform.hpp"
#include <cmath>

//test class to test/verify basic matrix transformation functionality and values for set cases
class test {
	public:
		void test_x_transform();
		void test_y_transform();
		void test_z_transform();
		void test_transform_on_empty();
		void test_rotation();	
		void test_scale();
		void run_all_tests();
	private:
};
