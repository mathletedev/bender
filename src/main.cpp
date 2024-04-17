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
	cube.add_vertex({-0.5, -0.5, -0.5});
	cube.add_vertex({-0.5, -0.5, 0.5});
	cube.add_vertex({-0.5, 0.5, -0.5});
	cube.add_vertex({-0.5, 0.5, 0.5});
	cube.add_vertex({0.5, -0.5, -0.5});
	cube.add_vertex({0.5, -0.5, 0.5});
	cube.add_vertex({0.5, 0.5, -0.5});
	cube.add_vertex({0.5, 0.5, 0.5});
	cube.transform.position = {500, 500, 0};
	cube.transform.scale = {100, 100, 100};

	sf::Clock clock;
	bool redraw = true;

	sf::Event event;

	while (window.isOpen()) {
		// https://en.sfml-dev.org/forums/index.php?topic=10031.0
		if (clock.getElapsedTime().asSeconds() >= 1.0 / FPS) {
			clock.restart();

			redraw = true;

			cube.transform.rotation.x += 0.02;
			cube.transform.rotation.y += 0.04;
			cube.transform.rotation.z += 0.06;
		}

		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) window.close();
		}

		window.clear();

		window.draw(cube);

		window.display();
	}

	return 0;
}
