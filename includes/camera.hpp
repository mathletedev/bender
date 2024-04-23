#pragma once

#define _USE_MATH_DEFINES
#include "transform.hpp"
#include <cmath>

// stores camera transform
// referenced by solids to project into 2-space
class camera {
	public:
		camera();
		class transform transform;

		float get_camera_speed() const;
		void set_camera_speed(double const &new_speed);

		matrix get_projection_matrix() const;
	private:
		// camera movement
		float camera_speed_;

		// setup for projection
		float near_, far_;
		float aspect_ratio_;
		float fov_;
};
