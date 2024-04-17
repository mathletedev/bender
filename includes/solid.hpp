#pragma once

#include "camera.hpp"
#include "transform.hpp"
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Vertex.hpp>
#include <SFML/System/Vector3.hpp>
#include <stdexcept>
#include <vector>

class solid : public sf::Drawable {
	public:
		class transform transform;

		solid(camera *const &camera);

		void add_vertex(sf::Vector3f const &vertex);
		void add_edge(int const &v1, int const &v2);

		void draw(sf::RenderTarget &target,
			  sf::RenderStates states) const override;

	protected:
		std::vector<sf::Vector3f> vertices_;
		std::vector<std::vector<int>> edges_;
		camera *camera_;
};
