#pragma once

#include "camera.hpp"
#include "import.hpp"
#include <SFML/System/Vector3.hpp>
#include <stdexcept>
#include <string>

class import_obj : public import {
	public:
		solid import_file(std::string &path, camera *const &camera_);

	private:
		sf::Vector3f process_vertex(std::string const &line);
		std::vector<int> process_face(std::string const &line);
};
