#pragma once

#include "transform.hpp"

class camera {
	public:
		class transform transform;

		matrix get_projection_matrix(double const &z) const;
};
