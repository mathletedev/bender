#pragma once

#include "camera.hpp"
#include "renderobject.hpp"
#include "transform.hpp"
#include "utils.hpp"
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/ConvexShape.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Vertex.hpp>
#include <SFML/System/Vector3.hpp>
#include <limits>
#include <memory>
#include <queue>
#include <stdexcept>
#include <vector>

class solid {
	public:
		class transform transform;

		solid(camera *const &camera);

		void set_color(sf::Color const &color);

		void add_vertex(sf::Vector3f const &vertex);
		void add_face(std::vector<int> const &face);

		void draw(std::priority_queue<render_object> &objects) const;

	protected:
		std::vector<sf::Vector3f> vertices_;
		std::vector<std::vector<int>> faces_;
		sf::Color color_;
		camera *camera_;
};
