#include "utils.hpp"

double utils::distance(sf::Vector2f const &point1, sf::Vector2f const &point2) {
	return std::sqrt(std::pow(point1.x - point2.x, 2) +
			 std::pow(point1.y - point2.y, 2));
}

double utils::angle(sf::Vector2f const &point1, sf::Vector2f const &point2) {
	return std::atan2(point2.y - point1.y, point2.x - point1.x);
}

std::vector<std::string> utils::split_string(std::string input_string, std::string const &delim) {
	std::vector<std::string> res;
	while (!input_string.empty()) {
		std::string s = "";
		if (input_string.find(delim) != std::string::npos) { 
			// delim found
			s = input_string.substr(0, input_string.find(delim));
			res.push_back(s);
			input_string.erase(0, input_string.find(delim) + delim.size());
		} else {
			res.push_back(input_string);
			input_string.erase(0, input_string.size());
		}
	}
	return res;
}
