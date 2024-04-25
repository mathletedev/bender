#include "test.hpp"

//test the transform on the x-axis
//verify transformed matrix values for certain test case
void test::test_x_transform() {
	transform testData;
	sf::Vector3f vertex(0,0,0);
	testData.position = sf::Vector3f(1,0,0);
	matrix testMatrix = testData.to_matrix() * vertex;
	if (testMatrix.get(0,0) == 1) {
		std::cout << "Test x transform passed!" << std::endl;
	}
	else {
		std::cout << "Test x transform failed!" << std::endl;
	}
}

//test the transform on the y-axis
//verify transformed matrix values for certain test case
void test::test_y_transform() {
	transform testData;
	sf::Vector3f vertex(0,0,0);
	testData.position = sf::Vector3f(0,1,0);
	matrix testMatrix = testData.to_matrix() * vertex;
	if (testMatrix.get(1,0) == 1) {
		std::cout << "Test y transform passed!" << std::endl;
	}
	else {
		std::cout << "Test y transform failed!" << std::endl;
	}
}

//test the transform on the z-axis
//verify transformed matrix values for certain test case
void test::test_z_transform() {
	transform testData;
	sf::Vector3f vertex(0,0,0);
	testData.position = sf::Vector3f(0,0,1);
	matrix testMatrix = testData.to_matrix() * vertex;
	if (testMatrix.get(2,0) == 1) {
		std::cout << "Test z transform passed!" << std::endl;
	}
	else {
		std::cout << "Test z transform failed!" << std::endl;
	}
}

//test the transform on an empty
//verify transformed matrix values
void test::test_transform_on_empty() {
	transform testData;
	sf::Vector3f vertex(0,0,0);
	testData.position = sf::Vector3f(0,0,0);
	matrix testMatrix = testData.to_matrix() * vertex;
	if (testMatrix.get(0,0) == 0 && testMatrix.get(1,0) == 0 && testMatrix.get(2,0) == 0) {
		std::cout << "Test transform on empty passed!" << std::endl;
	}
	else {
		std::cout << "Test transform on empty failed" << std::endl;
	}
}


//test rotation
//rotate 90 degrees clockwise on test case
void test::test_rotation() {
	transform testData;
	sf::Vector3f vertex(1,1,1);
	testData.rotation = sf::Vector3f(M_PI / 2,0,0);
	matrix testMatrix = testData.to_matrix() * vertex;
	if (testMatrix.get(0,0) == 1 && round(testMatrix.get(1,0)) == -1 && round(testMatrix.get(2,0)) == 1) {
		std::cout << "Test rotation passed!" << std::endl;
	}
	else {
		std::cout << "Test rotation failed!" << std::endl;
	}
}

//test scale
//scale up by two
void test::test_scale() {
transform testData;
	sf::Vector3f vertex(1,0,0);
	testData.scale = sf::Vector3f(2,1,1);
	matrix testMatrix = testData.to_matrix() * vertex;
	if (testMatrix.get(0,0) == 2) {
		std::cout << "Test scale passed!" << std::endl;
	}
	else {
		std::cout << "Test scale failed!" << std::endl;
	}
}

//run all tests, wrapper function
void test::run_all_tests() {
	test test;
	test.test_x_transform();
	test.test_y_transform();
	test.test_z_transform();
	test.test_transform_on_empty();
	test.test_rotation();
	test.test_scale();
}
