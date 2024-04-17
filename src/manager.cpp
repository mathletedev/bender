#include "manager.hpp"

manager::manager() {
	srand(time(0));

	fps_ = 60;

	window_.create(sf::VideoMode(1000, 1000), "Bender");

	camera_ = camera();
	camera_.transform.position = {0, 0, 1};

	solid tetrahedron = polyhedra::make_tetrahedron(&camera_);
	tetrahedron.set_color(sf::Color::Magenta);
	tetrahedron.transform.position = {400, 600, 0};
	tetrahedron.transform.scale = {100, 100, 100};

	solids_.push_back(tetrahedron);

	solid cube = polyhedra::make_cube(&camera_);
	cube.set_color(sf::Color::Magenta);
	cube.transform.position = {400, 400, 0};
	cube.transform.scale = {100, 100, 100};

	solids_.push_back(cube);

	solid octahedron = polyhedra::make_octahedron(&camera_);
	octahedron.set_color(sf::Color::Magenta);
	octahedron.transform.position = {600, 400, 0};
	octahedron.transform.scale = {100, 100, 100};

	solids_.push_back(octahedron);

	solid icosaedron = polyhedra::make_icosaedron(&camera_);
	icosaedron.set_color(sf::Color::Magenta);
	icosaedron.transform.position = {600, 600, 0};
	icosaedron.transform.scale = {100, 100, 100};

	solids_.push_back(icosaedron);
}

void manager::run() {
	while (window_.isOpen()) {
		while (window_.pollEvent(event_)) {
			if (event_.type == sf::Event::Closed) window_.close();
		}

		if (fps_clock_.getElapsedTime().asSeconds() >= 1.0 / fps_) {
			fps_clock_.restart();
			update();
		}
	}
}

void manager::update() {
	solids_[0].transform.rotation.y += 0.05;
	solids_[0].transform.rotation.x += 0.05;
	solids_[1].transform.rotation.y += 0.05;
	solids_[1].transform.rotation.x += 0.05;
	solids_[2].transform.rotation.y += 0.05;
	solids_[2].transform.rotation.x += 0.05;
	solids_[3].transform.rotation.y += 0.05;
	solids_[3].transform.rotation.x += 0.05;

	window_.clear();

	process_solids();
	render_all();

	window_.display();
}

void manager::process_solids() {
	for (auto &solid : solids_)
		solid.draw(objects_);
}

void manager::render_all() {
	while (!objects_.empty()) {
		window_.draw(objects_.top());
		objects_.pop();
	}
}
