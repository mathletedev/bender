#pragma once

#include "solid.hpp"
#include "utils.hpp"
#include <fstream>
#include <string>

class importer {
	public:
		~importer() {
			import_stream_.close();
		};

		virtual solid import_file(std::string &path,
					  camera *const &camera) = 0;

	protected:
		std::ifstream import_stream_;
};
