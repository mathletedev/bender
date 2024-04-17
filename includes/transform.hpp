#pragma once

#include "matrix.hpp"
#include <SFML/System/Vector3.hpp>
#include <cmath>

class transform {
	public:
		sf::Vector3f position;
		sf::Vector3f rotation;
		sf::Vector3f scale;

		transform(sf::Vector3f position = sf::Vector3f(0, 0, 0),
			  sf::Vector3f rotation = sf::Vector3f(0, 0, 0),
			  sf::Vector3f scale = sf::Vector3f(1, 1, 1));

		matrix to_matrix() const;
};
