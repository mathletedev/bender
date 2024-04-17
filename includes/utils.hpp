#pragma once

#include <SFML/System/Vector2.hpp>
#include <cmath>

namespace utils {
	double distance(sf::Vector2f const &point1, sf::Vector2f const &point2);
	double angle(sf::Vector2f const &point1, sf::Vector2f const &point2);
} // namespace utils
