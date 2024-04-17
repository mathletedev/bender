#include "matrix.hpp"

matrix::matrix(int const &rows, int const &cols) {
	rows_ = rows;
	cols_ = cols;
	data_.assign(rows, std::vector<double>(cols, 0));
}

matrix::matrix(sf::Vector3f const &data) {
	rows_ = 4;
	cols_ = 1;
	data_.assign(rows_, std::vector<double>(cols_, 0));

	data_[0][0] = data.x;
	data_[1][0] = data.y;
	data_[2][0] = data.z;
	data_[3][0] = 1;
}

matrix matrix::identity(int const &size) {
	matrix res(size, size);

	for (int i = 0; i < size; ++i)
		res.data_[i][i] = 1;

	return res;
}

double const &matrix::get(int const &row, int const &col) const {
	if (row < 0 || row >= rows_ || col < 0 || col >= cols_)
		throw std::invalid_argument("Invalid matrix index");

	return data_[row][col];
}

void matrix::set(int const &row, int const &col, double const &value) {
	if (row < 0 || row >= rows_ || col < 0 || col >= cols_)
		throw std::invalid_argument("Invalid matrix index");

	data_[row][col] = value;
}

sf::Vector3f matrix::to_vector3f() const {
	if (rows_ != 4 || cols_ != 1)
		throw std::invalid_argument("Matrix dimensions do not match");

	return sf::Vector3f(data_[0][0], data_[1][0], data_[2][0]);
}

void matrix::print() const {
	for (int i = 0; i < rows_; ++i) {
		for (int j = 0; j < cols_; ++j)
			std::cout << data_[i][j] << " ";
		std::cout << std::endl;
	}
}

matrix matrix::operator+(matrix const &rhs) {
	if (rows_ != rhs.rows_ || cols_ != rhs.cols_)
		throw std::invalid_argument("Matrix dimensions do not match");

	matrix res(rows_, cols_);

	for (int i = 0; i < rows_; ++i) {
		for (int j = 0; j < cols_; ++j)
			res.data_[i][j] = data_[i][j] + rhs.data_[i][j];
	}

	return res;
}

matrix matrix::operator*(matrix const &rhs) {
	if (cols_ != rhs.rows_)
		throw std::invalid_argument("Matrix dimensions do not match");

	matrix res(rows_, rhs.cols_);

	for (int i = 0; i < rows_; ++i) {
		for (int j = 0; j < rhs.cols_; ++j) {
			for (int k = 0; k < cols_; ++k)
				res.data_[i][j] +=
				    data_[i][k] * rhs.data_[k][j];
		}
	}

	return res;
}

matrix matrix::operator*(double const &rhs) {
	matrix res(rows_, cols_);

	for (int i = 0; i < rows_; ++i) {
		for (int j = 0; j < cols_; ++j)
			res.data_[i][j] = data_[i][j] * rhs;
	}

	return res;
}
