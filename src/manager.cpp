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
	monke.set_color(sf::Color::Red);
	monke.transform.position = {-3, 0, 5};

	solids_.push_back(monke);

	solid tetrahedron = polyhedra::make_tetrahedron(&camera_);
	tetrahedron.set_color(sf::Color::Cyan);
	tetrahedron.transform.position = {3, 3, 5};

	solids_.push_back(tetrahedron);

	solid cube = polyhedra::make_cube(&camera_);
	cube.set_color(sf::Color::White);
	cube.transform.position = {0, 0, 5};

	solids_.push_back(cube);

	solid octahedron = polyhedra::make_octahedron(&camera_);
	octahedron.set_color(sf::Color::Yellow);
	octahedron.transform.position = {0, 3, 5};

	solids_.push_back(octahedron);

	solid icosahedron = polyhedra::make_icosahedron(&camera_);
	icosahedron.set_color(sf::Color::Blue);
	icosahedron.transform.position = {-3, 3, 5};

	solids_.push_back(icosahedron);
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
	// rotates all solids
	for (auto &solid : solids_)	{	
		solid.transform.rotation.y += 0.05;
		solid.transform.rotation.x += 0.05;
	}

	process_input();

	window_.clear();

	process_solids();
	add_axis();

	render_all();

	window_.display();
}

void manager::process_input()
{
	double screen_width = 1000, screen_height = 1000;
	sf::Vector2i origin(screen_width / 2, screen_height / 2);

	if (sf::Mouse::isButtonPressed(sf::Mouse::Right)) {
		// hide mouse
		window_.setMouseCursorVisible(false);

		// find change in mouse position
		sf::Vector2i delta_position = sf::Mouse::getPosition(window_) - origin;
		// reset mouse to origin
		sf::Mouse::setPosition(origin, window_);

		// change camera rotation
		camera_.transform.rotation.y += delta_position.x / screen_width;
		camera_.transform.rotation.x -= delta_position.y / screen_height;

		// get direction of camera
		//sf::Vector3f cam_dir;
		//cam_dir.x = -cos(camera_.transform.rotation.x) * sin(camera_.transform.rotation.y);
		//cam_dir.y = -sin(camera_.transform.rotation.x) * cos(camera_.transform.rotation.y);
		//cam_dir.z = cos(camera_.transform.rotation.y) * cos(camera_.transform.rotation.x);

		//std::cout << cam_dir.x << " " << cam_dir.y << " " << cam_dir.z << std::endl;

		// gain access to movement
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
			this->camera_.transform.position.z += camera_.get_camera_speed();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
			this->camera_.transform.position.z -= camera_.get_camera_speed();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
			this->camera_.transform.position.x += camera_.get_camera_speed();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
			this->camera_.transform.position.x -= camera_.get_camera_speed();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
			this->camera_.transform.position.y -= camera_.get_camera_speed();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)) {
			this->camera_.transform.position.y += camera_.get_camera_speed();
		}
	}
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

// adds axis into 
void manager::add_axis() {
	// half of total size, 5x5 grid
	int grid_size = 10;
	int grid_distance = 1;

	// x axis lines
	for (int i = -grid_size / 2; i < grid_size / 2; i++) {
		sf::Vector3f point1_3d(i, 0, -grid_size / 2);
		sf::Vector3f point2_3d(i, 0, grid_size / 2);

		sf::Vector2f point1_2d, point2_2d;
		
		// gets rotation matrix for camera
		class transform cam_rotation;
		cam_rotation.rotation = camera_.transform.rotation;

		// project point
		matrix point_proj_1 = camera_.get_projection_matrix() * (cam_rotation.to_matrix() * point1_3d);
		matrix point_proj_2 = camera_.get_projection_matrix() * (cam_rotation.to_matrix() * point2_3d);

		// set points to vector2f
		point1_2d.x = point_proj_1.get(0, 0);
		point1_2d.y = point_proj_1.get(1, 0);
		point2_2d.x = point_proj_2.get(0, 0);
		point2_2d.y = point_proj_2.get(1, 0);

		double length = utils::distance(point1_2d, point2_2d);
		double angle = utils::angle(point1_2d, point2_2d);

		// no line shape, so rotate a rectangle
		auto line = std::make_shared<sf::RectangleShape>(
		    sf::Vector2f(length, 4));
		line->rotate(angle * 180 / M_PI);
		line->setPosition(point1_2d);
		line->setOrigin(0, 2);

		line->setFillColor(sf::Color::White);

		objects_.push(render_object(
		    line,
		    0,
		    PRIORITIES::LINE));
	}

	for (int i = -grid_size / 2; i < grid_size / 2; i++) {
		sf::Vector3f point1(-grid_size / 2, 0, i);
		sf::Vector3f point2(grid_size / 2, 0, i);
	}
}