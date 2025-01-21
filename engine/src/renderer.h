#pragma once

#include "glm/mat4x4.hpp"
#include "utilities/draw_info.h"

#include <queue>
#include <stdint.h>
#include <memory>

namespace Polygame {
	class Renderer {
	public:
		Renderer(const uint32_t window_width = 1920, const uint32_t window_height = 1080);
		~Renderer();

		void Render(); // Called every frame
		void AddDrawObject(const DrawInfo& info);

	private:
		uint32_t m_quad = 0; // Primitive used for drawing 2D sprites
		std::queue<DrawInfo> m_render_queue; // Loaded with DrawInfo every frame
		std::unique_ptr<class Shader> m_base_shader = nullptr; // Shader used to draw 2D sprites
		glm::vec2 m_screen_resolution = glm::vec2(1920.f, 1080.f);

		uint32_t GetTextureFromDrawInfo(const DrawInfo& info) const; // Returns a texture uint32_t that can be bound with glBindTextureUnit
		glm::mat4 Renderer::DrawInfoToModelMatrix(const DrawInfo& draw_info) const; // Returns a model matrix corresponding to the given DrawInfo
	};
}