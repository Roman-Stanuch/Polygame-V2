#pragma once

#include "utilities/draw_info.h"

namespace Polygame {
	class Object {
	public:
		Object();
		Object(const DrawInfo& draw_info);
		virtual ~Object() {}
		virtual void Tick(float delta_time) {}

		void Move(glm::vec3 direction, float distance);

		void Delete(); // Object will be set for deletion before next call to tick
		bool ShouldDelete(); // Returns true if object has been set for deletion on next tick

	private:
		DrawInfo m_draw_info;
		bool m_should_delete = false;
		bool m_is_visible = true;

	public:
		inline glm::vec3 GetPosition() const { return m_draw_info.pos; }
		inline void SetPosition(const glm::vec3 position) { m_draw_info.pos = position; }

		inline bool GetVisibility() const { return m_is_visible; }
		inline void SetVisibility(bool is_visible) { m_is_visible = is_visible; }

		inline const DrawInfo& GetDrawInfo() const { return m_draw_info; }
	};
}