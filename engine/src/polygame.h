#pragma once

#include <stdint.h>

namespace Polygame {
	class Object;

	void Init();
	void Init(uint32_t window_width, uint32_t window_height, bool fullscreen);

	void Start();
	void Tick();
	void End();

	void SetBackgroundColor(float red, float green, float blue, float alpha);
	void AddObject(const Object& object);
}