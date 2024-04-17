#include "camera.hpp"

matrix camera::get_projection_matrix(double const &z) const {
	// https://www.youtube.com/watch?v=p4Iz0XJY-Qk
	// double scale = 1 / (transform.position.z - z);

	double scale = 1;

	matrix res = matrix(2, 4);

	res.set(0, 0, scale);
	res.set(1, 1, scale);

	return res;
}
