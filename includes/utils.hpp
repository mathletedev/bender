#pragma once

#include <SFML/System/Vector2.hpp>
#include <cmath>
#include <string>
#include <vector>

namespace utils {
	double distance(sf::Vector2f const &point1, sf::Vector2f const &point2);
	double angle(sf::Vector2f const &point1, sf::Vector2f const &point2);
	std::vector<std::string> split_string(std::string input_string,
					      std::string const &delim);
} // namespace utils
