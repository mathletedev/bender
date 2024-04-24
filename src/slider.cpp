#include "slider.hpp"

void slider::update(sf::Vector2i &mouse_pos) {
	if (mouse_pos.x >= slider_pos_.x &&
	    mouse_pos.x <= slider_pos_.x + dim_.y &&
	    mouse_pos.y >= slider_pos_.y &&
	    mouse_pos.y <= slider_pos_.y + dim_.y) {
		if (mouse_pos.x >= pos_.x && mouse_pos.x <= pos_.x + dim_.x) {
			slider_pos_.x = mouse_pos.x;
		}
	}

	draw_gui();
}

void slider::draw_gui() {
	sf::RectangleShape bg, slider;

	bg.setPosition(pos_);
	bg.setSize(dim_);
	bg.setFillColor(bg_color_);

	slider.setPosition(slider_pos_);
	slider.setSize(sf::Vector2f(dim_.y, dim_.y));
	slider.setFillColor(slider_color_);

	window_->draw(bg);
	window_->draw(slider);
}

// finds coordinates for slider based on current val
sf::Vector2f slider::to_coord() {
	return sf::Vector2f(
	    (dim_.x * (curr_val_ / max_val_)) - (dim_.y / 2) + pos_.x, pos_.y);
}

// finds value based on current position
double slider::to_val() {
	return (slider_pos_.x / dim_.x - dim_.y) * (max_val_ - min_val_);
}

double slider::get_value() {
	return to_val();
}
