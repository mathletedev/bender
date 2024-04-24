#pragma once

#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include "camera.hpp"

class gui {
	public:
		gui(sf::Vector2f &pos, double &width = 0, double &height = 0) {
			this->pos_ = pos;
			this->height_ = height;
			this->width_ = width;
		};

		virtual void draw_gui(sf::RenderWindow &window) = 0;

	protected:
		sf::RenderWindow window_;
		sf::Vector2f pos_;
		double width_, height_;
};