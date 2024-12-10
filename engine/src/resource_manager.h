#pragma once

#include <stdint.h>

namespace Polygame {
	namespace Resource {
		uint32_t GetTexture(const char* name, const char* path);
		void SetAssetFolderPath(const char* path);
	}
}