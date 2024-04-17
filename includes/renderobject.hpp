#pragma once

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <memory>

enum PRIORITIES {
	PLANE = 0,
	LINE = 1,
	POINT = 2,
};

class render_object : public sf::Drawable {
	public:
		render_object(std::shared_ptr<sf::Drawable> const &drawable,
			      double const &z, int const &priority);

		void draw(sf::RenderTarget &target,
			  sf::RenderStates states) const;

		bool operator<(render_object const &rhs) const;

	private:
		std::shared_ptr<sf::Drawable> drawable_;
		double z_;
		int priority_;
};
