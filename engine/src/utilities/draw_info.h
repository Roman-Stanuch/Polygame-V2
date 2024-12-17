#pragma once

#include "glm/vec3.hpp"

namespace Polygame {
	struct DrawInfo {
		char* texture_name;
		char* texture_path;

		glm::vec3 pos = glm::vec3(0.f, 0.f, 0.f);
		glm::vec3 rot = glm::vec3(0.f, 0.f, 0.f);
		glm::vec3 scale = glm::vec3(10.f, 10.f, 10.f);
	};
}