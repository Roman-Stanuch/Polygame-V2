#include "renderer.h"
#include "shader.h"
#include "resource_manager.h"
#include "glad/glad.h"
#include "GLFW/glfw3.h"

#include "glm/gtc/matrix_transform.hpp"

#include <iostream>
#include <cstring>

namespace Polygame {
    Renderer::Renderer(const uint32_t window_width, const uint32_t window_height) :
        m_screen_resolution(window_width, window_height)
    {
        glClearColor(1.f, 0.f, 1.f, 1.0f);

        uint32_t VBO;
        float vertices[] = {
            // pos      // tex
            0.0f, 1.0f, 0.0f, 1.0f,
            1.0f, 0.0f, 1.0f, 0.0f,
            0.0f, 0.0f, 0.0f, 0.0f,

            0.0f, 1.0f, 0.0f, 1.0f,
            1.0f, 1.0f, 1.0f, 1.0f,
            1.0f, 0.0f, 1.0f, 0.0f
        };

        glGenVertexArrays(1, &m_quad);
        glGenBuffers(1, &VBO);

        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

        glBindVertexArray(m_quad);
        glEnableVertexAttribArray(0);
        glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)0);
        glBindBuffer(GL_ARRAY_BUFFER, 0);
        glBindVertexArray(0);

        m_base_shader = std::make_unique<Shader>("../../../../shaders/default_vertex.vert", "../../../../shaders/default_fragment.frag");
    }

    Renderer::~Renderer() {
        glDeleteVertexArrays(1, &m_quad);
    }


    void Renderer::Render() {
        glClear(GL_COLOR_BUFFER_BIT);

        m_base_shader->Use();
        m_base_shader->UMat4("projection", glm::ortho(0.0f, m_screen_resolution.x, m_screen_resolution.y, 0.0f, -1.0f, 1.0f));

        while (m_render_queue.size() > 0) {
            const DrawInfo& sprite_info = m_render_queue.front();
            m_base_shader->UMat4("model", DrawInfoToModelMatrix(sprite_info));
            m_base_shader->U3f("color_override", sprite_info.color);
            uint32_t tex = GetTextureFromDrawInfo(sprite_info);
            glBindTextureUnit(0, tex);
            glBindVertexArray(m_quad);
            glDrawArrays(GL_TRIANGLES, 0, 6);
            m_render_queue.pop();
        }
    }

    void Renderer::AddDrawObject(const DrawInfo& info) {
        m_render_queue.push(info);
    }

    uint32_t Renderer::GetTextureFromDrawInfo(const DrawInfo& info) const {
        if (strcmp("", info.texture_path)) {
            // Texture source has been set
            return Resource::GetTexture(info.texture_name, info.texture_path);
        }
        else {
            // Texture source not set, return blank texture
            return 0;
        }
    }

    glm::mat4 Renderer::DrawInfoToModelMatrix(const DrawInfo& draw_info) const {
        glm::mat4 model = glm::mat4(1.0f);
        model = glm::translate(model, draw_info.pos);
        model = glm::rotate(model, glm::radians(draw_info.rot.x), glm::vec3(1.0f, 0.0f, 0.0f));
        model = glm::rotate(model, glm::radians(draw_info.rot.y), glm::vec3(0.0f, 1.0f, 0.0f));
        model = glm::rotate(model, glm::radians(draw_info.rot.z), glm::vec3(0.0f, 0.0f, 1.0f));
        model = glm::scale(model, draw_info.scale);
        return model;
    }
}