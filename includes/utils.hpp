#pragma once

#include <SFML/System/Vector2.hpp>
#include <cmath>
#include <vector>
#include <string>

using std::string;
using std::vector;

namespace utils {
	double distance(sf::Vector2f const &point1, sf::Vector2f const &point2);
	double angle(sf::Vector2f const &point1, sf::Vector2f const &point2);
	vector<string> split_string(string input_string, string const &delim);
} // namespace utils
