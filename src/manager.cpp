#include "manager.hpp"

manager::manager() {
	fps_ = 60;

	window_.create(sf::VideoMode(1000, 1000), "Bender");

	camera_ = camera();
	camera_.transform.position = {0, 0, 1};

	solid cube = polyhedra::make_cube(&camera_);
	cube.set_color(sf::Color::Magenta);
	cube.transform.position = {500, 500, 0};
	cube.transform.scale = {100, 100, 100};

	solids_.push_back(cube);
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
