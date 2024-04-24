#pragma once

#include "gui.hpp"
#include <iostream>

class slider : public gui{
	public:
		slider(sf::RenderWindow *window, sf::Vector2f const &pos, sf::Color const &bg_color,
		       sf::Color const &slider_color, sf::Vector2f const &dim,
		       double const &min_val, double const &max_val, double const &start_val)
		    : gui(window, pos, dim) {
			this->bg_color_ = bg_color;
			this->slider_color_ = slider_color;
			this->max_val_ = max_val;
			this->min_val_ = min_val;
			this->curr_val_ = start_val;
			this->slider_pos_ = to_coord();
		};

		void update(sf::Vector2i &mouse_pos);
		double get_value();

	protected:
		void draw_gui();
		sf::Color bg_color_, slider_color_;
		double min_val_, max_val_, curr_val_;
		sf::Vector2f slider_pos_;

	private:
		sf::Vector2f to_coord();
		double to_val();
};