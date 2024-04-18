#pragma once

#include "transform.hpp"

// stores camera transform
// referenced by solids to project into 2-space
class camera {
	public:
		class transform transform;

		matrix get_projection_matrix(double const &z) const;
};
