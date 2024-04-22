#include "manager.hpp"

//manager constructor
manager::manager() {
	srand(time(0));

	fps_ = 60;

	window_.create(sf::VideoMode(1000, 1000), "Bender");

	camera_ = camera();
	camera_.transform.position = {0, 0, 1};

	std::string path = "./data/monkey.obj";
	import_obj obj_importer;
	solid monke = obj_importer.import_file(path, &camera_);
	monke.set_color(sf::Color::Transparent);
	monke.transform.position = {200, 600, 0};
	monke.transform.scale = {100, 100, 100};

	solids_.push_back(monke);

	solid tetrahedron = polyhedra::make_tetrahedron(&camera_);
	tetrahedron.set_color(sf::Color::Cyan);
	tetrahedron.transform.position = {400, 600, 0};
	tetrahedron.transform.scale = {100, 100, 100};

	solids_.push_back(tetrahedron);

	solid cube = polyhedra::make_cube(&camera_);
	cube.set_color(sf::Color::Magenta);
	cube.transform.position = {400, 400, 0};
	cube.transform.scale = {100, 100, 100};

	solids_.push_back(cube);

	solid octahedron = polyhedra::make_octahedron(&camera_);
	octahedron.set_color(sf::Color::Yellow);
	octahedron.transform.position = {600, 400, 0};
	octahedron.transform.scale = {100, 100, 100};

	solids_.push_back(octahedron);

	solid icosaedron = polyhedra::make_icosaedron(&camera_);
	icosaedron.set_color(sf::Color::Blue);
	icosaedron.transform.position = {600, 600, 0};
	icosaedron.transform.scale = {100, 100, 100};

	solids_.push_back(icosaedron);
}

// main loop
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

// updates every 1 / FPS seconds
void manager::update() {
	solids_[0].transform.rotation.y += 0.05;
	solids_[0].transform.rotation.x += 0.05;
	solids_[1].transform.rotation.y += 0.05;
	solids_[1].transform.rotation.x += 0.05;
	solids_[2].transform.rotation.y += 0.05;
	solids_[2].transform.rotation.x += 0.05;
	solids_[3].transform.rotation.y += 0.05;
	solids_[3].transform.rotation.x += 0.05;
	solids_[4].transform.rotation.y += 0.05;
	solids_[4].transform.rotation.x += 0.05;

	window_.clear();

	process_solids();
	render_all();

	window_.display();
}

// puts solids into objects queue
void manager::process_solids() {
	for (auto &solid : solids_)
		solid.render_into(objects_);
}

// draw all objects to window
void manager::render_all() {
	while (!objects_.empty()) {
		window_.draw(objects_.top());
		objects_.pop();
	}
}
