#include "transform.hpp"

transform::transform(sf::Vector3f position, sf::Vector3f rotation,
		     sf::Vector3f scale) {
	this->position = position;
	this->rotation = rotation;
	this->scale = scale;
}

matrix transform::to_matrix() const {
	matrix res = matrix::identity(4);

	// scale
	matrix scale = matrix::identity(4);
	scale.set(0, 0, this->scale.x);
	scale.set(1, 1, this->scale.y);
	scale.set(2, 2, this->scale.z);

	res = scale * res;

	// rotation
	matrix rot_x = matrix::identity(4);
	rot_x.set(1, 1, cos(rotation.x));
	rot_x.set(1, 2, -sin(rotation.x));
	rot_x.set(2, 1, sin(rotation.x));
	rot_x.set(2, 2, cos(rotation.x));

	matrix rot_y = matrix::identity(4);
	rot_y.set(0, 0, cos(rotation.y));
	rot_y.set(0, 2, sin(rotation.y));
	rot_y.set(2, 0, -sin(rotation.y));
	rot_y.set(2, 2, cos(rotation.y));

	matrix rot_z = matrix::identity(4);
	rot_z.set(0, 0, cos(rotation.z));
	rot_z.set(0, 1, -sin(rotation.z));
	rot_z.set(1, 0, sin(rotation.z));
	rot_z.set(1, 1, cos(rotation.z));

	res = rot_x * rot_y * rot_z * res;

	// translation
	res.set(0, 3, position.x);
	res.set(1, 3, position.y);
	res.set(2, 3, position.z);

	return res;
}
