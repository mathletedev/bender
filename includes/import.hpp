#pragma once

#include <fstream>
#include <string>
#include "solid.hpp"
#include "utils.hpp"

using std::string;

class import {
	public:
		~import() {import_stream_.close();};
		virtual solid import_file(string &path, camera *const &camera_) = 0;

	protected:
		std::ifstream import_stream_;
};