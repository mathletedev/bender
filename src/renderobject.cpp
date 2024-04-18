#include "renderobject.hpp"
#include <iostream>

render_object::render_object(std::shared_ptr<sf::Drawable> const &drawable,
			     double const &z, int const &priority) {
	drawable_ = drawable;
	z_ = z;
	priority_ = priority;
}

void render_object::draw(sf::RenderTarget &target,
			 sf::RenderStates states) const {
	target.draw(*drawable_, states);
}

// used for sorting into priority queue
bool render_object::operator<(render_object const &rhs) const {
	if (z_ == rhs.z_) return priority_ > rhs.priority_;
	return (z_ < rhs.z_);
}
