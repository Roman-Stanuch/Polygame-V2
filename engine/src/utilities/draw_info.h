#pragma once

#include "glm/vec3.hpp"

namespace Polygame {
	struct DrawInfo {
		// Set to "color" for a blank texture that uses only the color member.
		char* texture_name = "";
		char* texture_path = "";

		// Additive. Set texture_name to "color" to use only color and no texture.
		glm::vec3 color = glm::vec3(0.f, 0.f, 0.f);
		glm::vec3 pos = glm::vec3(0.f, 0.f, 0.f);
		glm::vec3 rot = glm::vec3(0.f, 0.f, 0.f);
		glm::vec3 scale = glm::vec3(10.f, 10.f, 10.f);
	};
}