#include "renderobject.hpp"
#include <iostream>

render_object::render_object(std::shared_ptr<sf::Drawable> const &drawable,
			     double const &z) {
	drawable_ = drawable;
	z_ = z;
}

void render_object::draw(sf::RenderTarget &target,
			 sf::RenderStates states) const {
	target.draw(*drawable_, states);
}

bool render_object::operator<(render_object const &rhs) const {
	return z_ < rhs.z_;
}
