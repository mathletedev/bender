#include "test.hpp"

void test::test_transform() {
	transform testData;
	testData.position = sf::Vector3f(1,0,0);
	matrix testMatrix = testData.to_matrix() * sf::Vector3f(0,0,0);
	if (testMatrix.get(0,0) == 1) {
		std::cout << "Test transform passed!" << std::endl;
	}
	else {
		std::cout << "Test transform failed!" << std::endl;
	}
}

void test::test_rotation() {
}

void test::test_scale() {
}

void test::test_transform_on_empty() {
}

void test::test_import_obj() {
}
