#pragma once

#include "camera.hpp"
#include "solid.hpp"

namespace polyhedra {
	solid make_tetrahedron(camera *camera);
	solid make_cube(camera *camera);
	solid make_octahedron(camera *camera);
	solid make_icosaedron(camera *camera);
} // namespace polyhedra
