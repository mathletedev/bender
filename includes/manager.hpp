#pragma once

#include "camera.hpp"
#include "polyhedra.hpp"
#include "renderobject.hpp"
#include "import_obj.hpp"
#include "solid.hpp"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include <cstdlib>
#include <ctime>
#include <queue>

class manager {
	public:
		manager();

		void run();
		void update();
		void process_solids();
		void render_all();

	private:
		double fps_;
		sf::RenderWindow window_;
		camera camera_;
		std::vector<solid> solids_;
		std::priority_queue<render_object> objects_;
		sf::Clock fps_clock_;
		sf::Event event_;
};
