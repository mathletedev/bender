#pragma once

#include <SFML/System/Vector3.hpp>
#include <iostream>
#include <stdexcept>
#include <vector>

// useful for manipulating transforms
class matrix {
	public:
		matrix(int const &rows = 0, int const &cols = 0);
		matrix(sf::Vector3f const &data);

		static matrix identity(int const &size);

		double const &get(int const &row, int const &col) const;
		void set(int const &row, int const &col, double const &value);

		sf::Vector3f to_vector3f() const;

		void print() const;

		matrix operator+(matrix const &rhs);
		matrix operator-(matrix const &rhs);
		matrix operator*(matrix const &rhs);
		matrix operator*(double const &rhs);

	private:
		int rows_;
		int cols_;
		std::vector<std::vector<double>> data_;
};
