#pragma once

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RenderTarget.hpp>

class render_object : public sf::Drawable {
	public:
		render_object(sf::Drawable *const drawable, double const &z);

		~render_object();

		void draw(sf::RenderTarget &target,
			  sf::RenderStates states) const;

		bool operator<(render_object const &rhs) const;

	private:
		sf::Drawable *drawable_;
		double z_;
};
