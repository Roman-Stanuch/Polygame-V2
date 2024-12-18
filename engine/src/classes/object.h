#pragma once

#include "utilities/draw_info.h"

namespace Polygame {
	class Object {
	public:
		Object();
		virtual void Tick(double deltaTime);

		void SetPosition(glm::vec3 position);
		void Move(glm::vec3 direction, float distance);

		void Delete();
		bool ShouldDelete();

	private:
		DrawInfo m_draw_info;
		bool m_should_delete = false;
	};
}