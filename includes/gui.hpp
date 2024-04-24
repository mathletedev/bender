#pragma once

#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include "camera.hpp"

class gui {
	public:
		gui(sf::RenderWindow *window, sf::Vector2f const &pos, sf::Vector2f const &dim) {
			this->pos_ = pos;
			this->dim_ = dim;
			this->window_ = window;
		};

		virtual void update(sf::Vector2i &mouse_pos) = 0;

	protected:
		virtual void draw_gui() = 0;
		sf::RenderWindow *window_;
		sf::Vector2f pos_, dim_;
};