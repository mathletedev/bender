#include "renderobject.hpp"

render_object::render_object(sf::Drawable *const drawable, double const &z) {
	drawable_ = drawable;
	z_ = z;
}

render_object::~render_object() {
	delete drawable_;
}

void render_object::draw(sf::RenderTarget &target,
			 sf::RenderStates states) const {
	target.draw(*drawable_, states);
}

bool render_object::operator<(render_object const &rhs) const {
	return z_ < rhs.z_;
}
