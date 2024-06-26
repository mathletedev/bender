#pragma once

#include "camera.hpp"
#include "importobj.hpp"
#include "polyhedra.hpp"
#include "renderobject.hpp"
#include "solid.hpp"
#include "slider.hpp"
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/System/Vector2.hpp>
#include <cstdlib>
#include <ctime>
#include <queue>

class manager {
	public:
		manager();

		void run();
		void update();
		void process_input();
		void process_solids();
		void render_all();
		void draw_text(); 

	private:
		double fps_;
		int i = 0, total_size, num1_pressed = 0,
			r_pressed = 0, g_pressed = 0, s_pressed = 0, 
			x_pressed = 0, y_pressed = 0, z_pressed = 0; 
		float original_r = 0, original_g = 0, original_b = 0; 
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
		sf::Font font;
};
