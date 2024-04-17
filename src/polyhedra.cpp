#include "polyhedra.hpp"

solid polyhedra::make_tetrahedron(camera *camera) {
	solid tetrahedron(camera);

	float jit = 1 / sqrt(2);

	tetrahedron.add_vertex({-1, 0, -jit});
	tetrahedron.add_vertex({1, 0, -jit});
	tetrahedron.add_vertex({0, -1, jit});
	tetrahedron.add_vertex({0, 1, jit});

	tetrahedron.add_face({0, 1, 2});
	tetrahedron.add_face({0, 1, 3});
	tetrahedron.add_face({0, 2, 3});
	tetrahedron.add_face({1, 2, 3});

	return tetrahedron;
}

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

solid polyhedra::make_octahedron(camera *camera) {
	solid octahedron(camera);

	octahedron.add_vertex({-1, 0, 0});
	octahedron.add_vertex({1, 0, 0});
	octahedron.add_vertex({0, -1, 0});
	octahedron.add_vertex({0, 1, 0});
	octahedron.add_vertex({0, 0, -1});
	octahedron.add_vertex({0, 0, 1});

	octahedron.add_face({0, 2, 4});
	octahedron.add_face({0, 2, 5});
	octahedron.add_face({0, 3, 4});
	octahedron.add_face({0, 3, 5});
	octahedron.add_face({1, 2, 4});
	octahedron.add_face({1, 2, 5});
	octahedron.add_face({1, 3, 4});
	octahedron.add_face({1, 3, 5});

	return octahedron;
}

solid polyhedra::make_icosaedron(camera *camera) {
	solid icosahedron(camera);

	// eric's jit
	float jit = 5 / (sqrt(50 - (10 * sqrt(5))));

	icosahedron.add_vertex({0, 0, -jit});
	icosahedron.add_vertex({0, 0, jit});

	float jits = sqrt(2 / (5 - sqrt(5)));
	jit = 1 / (sqrt(10 - (2 * sqrt(5))));

	icosahedron.add_vertex({-jits, 0, -jit});
	icosahedron.add_vertex({jits, 0, jit});

	jits = (1 + sqrt(5)) / (2 * sqrt(10 - (2 * sqrt(5))));

	icosahedron.add_vertex({jits, -0.5, -jit});
	icosahedron.add_vertex({jits, 0.5, -jit});
	icosahedron.add_vertex({-jits, -0.5, jit});
	icosahedron.add_vertex({-jits, 0.5, jit});

	jits = (-1 + sqrt(5)) / (2 * sqrt(10 - (2 * sqrt(5))));
	float jitses = 0.5 * sqrt((5 + sqrt(5)) / (5 - sqrt(5)));

	icosahedron.add_vertex({-jits, -jitses, -jit});
	icosahedron.add_vertex({-jits, jitses, -jit});
	icosahedron.add_vertex({jits, -jitses, jit});
	icosahedron.add_vertex({jits, jitses, jit});

	icosahedron.add_face({0, 4, 5});  // olive green
	icosahedron.add_face({3, 4, 5});  // macaroni orange
	icosahedron.add_face({3, 4, 10}); // orange yellow
	icosahedron.add_face({0, 4, 8});  // mahogany
	icosahedron.add_face({4, 8, 10}); // poop
	icosahedron.add_face({6, 8, 10}); // green
	icosahedron.add_face({1, 3, 10}); // dark navy blue
	icosahedron.add_face({1, 6, 10}); // salmon
	icosahedron.add_face({2, 6, 8});  // green but darker
	icosahedron.add_face({0, 2, 8});  // grape
	icosahedron.add_face({1, 6, 7});  // scarlet
	icosahedron.add_face({2, 6, 7});  // light salmon
	icosahedron.add_face({0, 2, 9});  // light grape
	icosahedron.add_face({2, 7, 9});  // smoothie
	icosahedron.add_face({0, 5, 9});  // cyan
	icosahedron.add_face({1, 7, 11}); // dark blue
	icosahedron.add_face({1, 3, 11});
	icosahedron.add_face({7, 9, 11});
	icosahedron.add_face({3, 5, 11});
	icosahedron.add_face({5, 9, 11});

	return icosahedron;
}
