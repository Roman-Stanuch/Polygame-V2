#pragma once

#include "utilities/draw_info.h"

namespace Polygame {
	class Object {
	public:
		Object();
		virtual ~Object() {}
		virtual void Tick(float delta_time);

		void SetPosition(glm::vec3 position);
		glm::vec3 GetPosition() const;

		void Move(glm::vec3 direction, float distance);

		void Delete();
		bool ShouldDelete();

	private:
		DrawInfo m_draw_info;
		bool m_should_delete = false;
	};
}