#include "object.h"
#include "renderer.h"

namespace Polygame {
	Object::Object() {
		m_draw_info.scale = glm::vec3(100.f, 100.f, 100.f);
		m_draw_info.texture_name = "tex";
		m_draw_info.texture_path = "album_cover.png";
	}

	void Object::Tick(double deltaTime)
	{
		Renderer::AddDrawObject(m_draw_info);
	}
}