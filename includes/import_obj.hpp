#pragma once

#include "import.hpp"
#include <stdexcept>

class import_obj : public import {
	public:
		solid import_file(string &path, camera *const &camera_);

	private:
		sf::Vector3f process_vertex(string &line);
		vector<int> process_face(string &line);
};