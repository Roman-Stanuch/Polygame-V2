#include "object.h"

namespace Polygame {
	Object::Object() :
		m_is_visible(false) // No draw info; do not draw
	{

	}

	Object::Object(const DrawInfo& draw_info) :
		m_draw_info(draw_info)
	{
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