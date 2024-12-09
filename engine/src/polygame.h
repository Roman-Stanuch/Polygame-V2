#pragma once

#include "window.h"

namespace Polygame {
	void Init();
	void Init(uint32_t window_width, uint32_t window_height, bool fullscreen);

	void Tick();

	void Deinit();

	void SetBackgroundColor(float red, float green, float blue, float alpha);
}