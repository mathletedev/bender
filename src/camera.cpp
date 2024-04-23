#include "camera.hpp"

camera::camera() {
	fov_ = M_PI / 2; // 90degrees
	aspect_ratio_ = 1000.0/1000.0;
	near_ = 0.001;
	far_ = 100.0;
	camera_speed_ = .1;
}

float camera::get_camera_speed() const {
	return camera_speed_;
}

void camera::set_camera_speed(double const& new_speed) {
	camera_speed_ = new_speed;
}

matrix camera::get_projection_matrix() const {
	matrix res(4,4);

	res.set(0, 0, 1 / (aspect_ratio_ * tan(fov_ / 2)));
	res.set(1, 1, 1 / tan(fov_ / 2));
	res.set(2, 2, far_ / (far_ - near_));
	res.set(3, 2, 1);
	res.set(2, 3, -(far_ * near_) / (far_ - near_));

	return res;
}
