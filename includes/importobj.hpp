#pragma once

#include "camera.hpp"
#include "importer.hpp"
#include <SFML/System/Vector3.hpp>
#include <stdexcept>
#include <string>

class import_obj : public importer {
	public:
		solid import_file(std::string &path,
				  camera *const &camera) override;

	private:
		sf::Vector3f process_vertex(std::string const &line) const;
		std::vector<int> process_face(std::string const &line) const;
};
