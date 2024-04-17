#pragma once

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <memory>

class render_object : public sf::Drawable {
	public:
		render_object(std::shared_ptr<sf::Drawable> const &drawable,
			      double const &z);

		void draw(sf::RenderTarget &target,
			  sf::RenderStates states) const;

		bool operator<(render_object const &rhs) const;

	private:
		std::shared_ptr<sf::Drawable> drawable_;
		double z_;
};
