#pragma once

#include "camera.hpp"
#include "transform.hpp"
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/ConvexShape.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Vertex.hpp>
#include <SFML/System/Vector3.hpp>
#include <stdexcept>
#include <vector>

class solid : public sf::Drawable {
	public:
		class transform transform;

		solid(sf::Color const &color, camera *const &camera);

		void add_vertex(sf::Vector3f const &vertex);
		void add_face(std::vector<int> const &face);

		void draw(sf::RenderTarget &target,
			  sf::RenderStates states) const override;

	protected:
		std::vector<sf::Vector3f> vertices_;
		std::vector<std::vector<int>> faces_;
		sf::Color color_;
		camera *camera_;
};
