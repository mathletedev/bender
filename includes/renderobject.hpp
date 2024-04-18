#pragma once

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <memory>

// higher priority = drawn on top
enum PRIORITIES {
	PLANE = 0,
	LINE = 1,
	POINT = 2,
};

// stores a drawable and a z-index for priority queue sorting
// SFML does not have a system for handling z-indices
class render_object : public sf::Drawable {
	public:
		render_object(std::shared_ptr<sf::Drawable> const &drawable,
			      double const &z, int const &priority);

		void draw(sf::RenderTarget &target,
			  sf::RenderStates states) const override;

		bool operator<(render_object const &rhs) const;

	private:
		// use a shared_ptr for copying pointers
		std::shared_ptr<sf::Drawable> drawable_;
		double z_;
		int priority_;
};
