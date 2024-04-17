#include "utils.hpp"

double utils::distance(sf::Vector2f const &point1, sf::Vector2f const &point2) {
	return std::sqrt(std::pow(point1.x - point2.x, 2) +
			 std::pow(point1.y - point2.y, 2));
}

double utils::angle(sf::Vector2f const &point1, sf::Vector2f const &point2) {
	return std::atan2(point2.y - point1.y, point2.x - point1.x);
}
