#include "import_obj.hpp"


solid import_obj::import_file(string &path, camera *const &camera_) {
	if (path.substr(path.size() - 4, 4) != ".obj")
		throw std::invalid_argument("File not .obj format");

	this->import_stream_.open(path);

	string line = "";
	solid new_obj(camera_);
	while (getline(this->import_stream_, line)) {
		if (line.substr(0, 2) == "v ") {
			// read in vertex
			new_obj.add_vertex(
			    process_vertex(line.substr(2, line.size() - 2)));
		} else if (line.substr(0, 2) == "f ") {
			// read in face
			new_obj.add_face(
			    process_face(line.substr(2, line.size() - 2)));
		}
	}
	return new_obj;
}

sf::Vector3f import_obj::process_vertex(string &line) {
	vector<string> res = utils::split_string(line, " ");
	return {stof(res[0]), stof(res[1]), stof(res[2])};
}

vector<int> import_obj::process_face(string& line) {
	vector<string> res = utils::split_string(line, " ");
	vector<int> face;
	for (string part : res)
	{
		face.push_back(stoi(utils::split_string(part, "/")[0]) - 1);
	}
	return face;
}