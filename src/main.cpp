#include "camera.hpp"
#include "solid.hpp"
#include <SFML/Graphics.hpp>

#define FPS 60

int main() {
	sf::RenderWindow window;
	window.create(sf::VideoMode(1000, 1000), "Bender");

	camera camera;
	camera.transform.position = {0, 0, 1};

	solid cube(sf::Color::Magenta, &camera);
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
