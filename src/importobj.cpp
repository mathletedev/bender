#include "importobj.hpp"

solid import_obj::import_file(std::string &path, camera *const &camera) {
	if (path.substr(path.size() - 4, 4) != ".obj")
		throw std::invalid_argument("File not .obj format");

	import_stream_.open(path);

	std::string line = "";
	solid new_obj(camera);
	while (getline(import_stream_, line)) {
		std::string marker = line.substr(0, line.find(" "));

		// cannot switch on strings
		if (marker == "v") {
			// read in vertex
			new_obj.add_vertex(
			    process_vertex(line.substr(2, line.size() - 2)));
		} else if (marker == "f") {
			// read in face
			new_obj.add_face(
			    process_face(line.substr(2, line.size() - 2)));
		}
	}

	import_stream_.close();

	return new_obj;
}

sf::Vector3f import_obj::process_vertex(std::string const &line) const {
	std::vector<std::string> res = utils::split_string(line, " ");
	return {stof(res[0]), stof(res[1]), stof(res[2])};
}

std::vector<int> import_obj::process_face(std::string const &line) const {
	std::vector<std::string> res = utils::split_string(line, " ");
	std::vector<int> face;

	for (std::string part : res)
		face.push_back(stoi(utils::split_string(part, "/")[0]) - 1);

	return face;
}
