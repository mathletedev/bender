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

		matrix get_projection_matrix() const;
	private:
		float aspect_ratio_;
		float fov_;
		// setup for frustrum
		float near_, far_;
};
