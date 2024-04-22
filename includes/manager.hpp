#pragma once

#include "camera.hpp"
#include "importobj.hpp"
#include "polyhedra.hpp"
#include "renderobject.hpp"
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
		// queue of objects to render, prioritised by z-index
		// - O(log N) time for insertion
		// - O(N log N) time for inserting N objects
		// - O(log N) time for deletion
		// - O(N log N) time for delting N objects
		// could also use a vector and sort with std::sort,
		// which would use O(N log N) time
		// decided to use a priority queue as it fits the task better
		std::priority_queue<render_object> objects_;
		sf::Clock fps_clock_;
		sf::Event event_;
};