#pragma once

#include "utilities/draw_info.h"

namespace Polygame {
	class Object {
	public:
		Object();
		virtual void Tick(double deltaTime);

	private:
		DrawInfo m_draw_info;
	};
}