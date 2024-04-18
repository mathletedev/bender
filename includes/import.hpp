#pragma once

#include "solid.hpp"
#include "utils.hpp"
#include <fstream>
#include <string>

class import {
	public:
		~import() {
			import_stream_.close();
		};
		virtual solid import_file(std::string &path,
					  camera *const &camera_) = 0;

	protected:
		std::ifstream import_stream_;
};
