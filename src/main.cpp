#include "camera.hpp"
#include "solid.hpp"
#include <SFML/Graphics.hpp>

#define FPS 60

int main() {
	sf::RenderWindow window;
	window.create(sf::VideoMode(1000, 1000), "Bender");

	camera camera;
	camera.transform.position = {0, 0, 1};

	solid cube(&camera);
	solid icosahedron(&camera); 
	//cube.add_vertex({-0.5, -0.5, -0.5});
	//cube.add_vertex({-0.5, -0.5, 0.5});
	//cube.add_vertex({-0.5, 0.5, -0.5});
	//cube.add_vertex({-0.5, 0.5, 0.5});
	//cube.add_vertex({0.5, -0.5, -0.5});
	//cube.add_vertex({0.5, -0.5, 0.5});
	//cube.add_vertex({0.5, 0.5, -0.5});
	//cube.add_vertex({0.5, 0.5, 0.5});
	//cube.add_vertex({0.5, 0.5, 0.5});

	float jit = 5 / (sqrt(50 - (10 * sqrt(5))));

	cube.add_vertex({0, 0, -jit}); 
	cube.add_vertex({0, 0, jit}); 

	float jits = sqrt(2 / (5 - sqrt(5)));
	jit = 1 / (sqrt(10 - (2 * sqrt(5))));

	cube.add_vertex({-jits, 0, -jit}); 
	cube.add_vertex({jits, 0, jit}); 

	jits = (1 + sqrt(5))/(2 * sqrt(10 - (2 * sqrt(5))));

	cube.add_vertex({jits, -0.5, -jit}); 
	cube.add_vertex({jits, 0.5, -jit}); 
	cube.add_vertex({-jits, -0.5, jit}); 
	cube.add_vertex({-jits, 0.5, jit}); 

	jits = (-1 + sqrt(5)) / (2 * sqrt(10 - (2 * sqrt(5))));
	float jitses = 0.5 * sqrt((5 + sqrt(5))/(5 - sqrt(5))); 

	cube.add_vertex({-jits, -jitses, -jit});
	cube.add_vertex({-jits, jitses, -jit});
	cube.add_vertex({jits, -jitses, jit});
	cube.add_vertex({jits, jitses, jit});


	cube.transform.position = {500, 500, 0};
	cube.transform.scale = {100, 100, 100};

	sf::Clock clock;

	sf::Event event;

	while (window.isOpen()) {
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) window.close();
		}

		// https://en.sfml-dev.org/forums/index.php?topic=10031.0
		if (clock.getElapsedTime().asSeconds() < 1.0 / FPS) continue;
		clock.restart();

		cube.transform.rotation.y += 0.05;
		cube.transform.rotation.x += 0.05;

		window.clear();

		window.draw(cube);

		window.display();
	}

	return 0;
}
