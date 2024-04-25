#include "test.hpp"

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

void test::test_rotation() {
	transform testData;
	sf::Vector3f vertex(1,0,0);
	testData.rotation = sf::Vector3f(90,0,0);
	matrix testMatrix = testData.to_matrix() * vertex;
	if (testMatrix.get(0,0) != 1) {
		std::cout << "Test rotation passed!" << std::endl;
	}
	else {
		std::cout << "Test rotation failed!" << std::endl;
	}
}

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
