#pragma once

#include "utilities/draw_info.h"

namespace Polygame {
	namespace Renderer {
		void Init();
		void Deinit();
		void Render();
		void AddDrawObject(const DrawInfo& info);
	}
}