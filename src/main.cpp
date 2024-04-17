#include "camera.hpp"
#include "solid.hpp"
#include <SFML/Graphics.hpp>

#define FPS 60

int main() {
	sf::RenderWindow window;
	window.create(sf::VideoMode(1000, 1000), "Bender");

	camera camera;
	camera.transform.position = {0, 0, 1};

	srand((unsigned)time(NULL)); 
	solid cube(sf::Color::Magenta, &camera);
	//solid icosahedron(&camera); 
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

	cube.add_face({0, 4, 5}); //olive green
	cube.add_face({3, 4, 5}); //macaroni orange
	cube.add_face({3, 4, 10}); //orange yellow
	cube.add_face({0, 4, 8}); //mahogany
	cube.add_face({4, 8, 10}); //poop
	cube.add_face({6, 8, 10}); // green
	cube.add_face({1, 3, 10}); //dark navy blue
	cube.add_face({1, 6, 10}); //salmon
	cube.add_face({2, 6, 8}); //green but darker
	cube.add_face({0, 2, 8}); //grape
	cube.add_face({1, 6, 7}); //scarlet
	cube.add_face({2, 6, 7}); //light salmon
	cube.add_face({0, 2, 9}); //light grape
	cube.add_face({2, 7, 9}); //smoothie
	cube.add_face({0, 5, 9}); //cyan
	cube.add_face({1, 7, 11}); //dark blue
	cube.add_face({1, 3, 11}); 
	cube.add_face({7, 9, 11}); 
	cube.add_face({3, 5, 11}); 
	cube.add_face({5, 9, 11}); 

	cube.transform.position = {500, 500, 0};
	cube.transform.scale = {300, 300, 300};

	sf::Clock clock;

	sf::Event event;

	while (window.isOpen()) {
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) window.close();
		}

		// https://en.sfml-dev.org/forums/index.php?topic=10031.0
		if (clock.getElapsedTime().asSeconds() < 1.0 / FPS) continue;
		clock.restart();

		cube.transform.rotation.y += 0.03;
		cube.transform.rotation.x += 0.03;
		cube.transform.rotation.z += 0.03;


		window.clear();

		window.draw(cube);

		window.display();
	}

	return 0;
}
