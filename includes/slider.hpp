#pragma once

#include "gui.hpp"

class slider : public gui{
	public:
		slider(sf::Vector2f &pos, sf::Color &bg_color,
		       sf::Color &button_color, double &width = 0, double &height = 0,
		       double &min_val = 0, double &max_val = 1)
		    : gui(pos, width, height) {
			this->bg_color_ = bg_color;
			this->button_color_ = button_color;
			this->max_val = max_val;
			this->min_val_ = min_val;
		};

		void draw_gui(sf::RenderWindow &window);

	protected:
		sf::Color bg_color_, button_color_;
		double min_val_, max_val_;
};