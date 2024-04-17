#include "polyhedra.hpp"

solid polyhedra::make_cube(camera *camera) {
	solid cube(camera);

	cube.add_vertex({-0.5, -0.5, -0.5});
	cube.add_vertex({-0.5, -0.5, 0.5});
	cube.add_vertex({-0.5, 0.5, 0.5});
	cube.add_vertex({-0.5, 0.5, -0.5});
	cube.add_vertex({0.5, -0.5, -0.5});
	cube.add_vertex({0.5, -0.5, 0.5});
	cube.add_vertex({0.5, 0.5, 0.5});
	cube.add_vertex({0.5, 0.5, -0.5});
	cube.add_face({0, 1, 2, 3});
	cube.add_face({4, 5, 6, 7});
	cube.add_face({0, 1, 5, 4});
	cube.add_face({1, 2, 6, 5});
	cube.add_face({2, 3, 7, 6});
	cube.add_face({3, 0, 4, 7});

	return cube;
}
