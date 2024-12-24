#include "object.h"
#include "renderer.h"

namespace Polygame {
	Object::Object() {
		m_draw_info.scale = glm::vec3(100.f, 100.f, 100.f);
		m_draw_info.texture_name = "tex";
		m_draw_info.texture_path = "album_cover.png";
		m_draw_info.color = glm::vec3(0.f, 0.f, 0.f);
	}

	void Object::Tick(float delta_time)
	{
		Renderer::AddDrawObject(m_draw_info);
	}

	void Object::SetPosition(glm::vec3 position)
	{
		m_draw_info.pos = position;
	}

	glm::vec3 Object::GetPosition() const
	{
		return m_draw_info.pos;
	}

	void Object::Move(glm::vec3 direction, float distance)
	{
		m_draw_info.pos += (direction * distance);
	}

	void Object::Delete()
	{
		m_should_delete = true;
	}

	bool Object::ShouldDelete()
	{
		return m_should_delete;
	}
}