#include "renderer.h"
#include "shader.h"
#include "resource_manager.h"
#include "utilities/draw_info.h"
#include "glad/glad.h"
#include "GLFW/glfw3.h"

#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"

#include <queue>
#include <iostream>
#include <cstring>

namespace Polygame {
    namespace Renderer {
        static uint32_t quad = 0;
        static std::queue<DrawInfo> render_queue;
        static Polygame::Shader* base_shader = nullptr;

        void Init() {
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

            glGenVertexArrays(1, &quad);
            glGenBuffers(1, &VBO);

            glBindBuffer(GL_ARRAY_BUFFER, VBO);
            glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

            glBindVertexArray(quad);
            glEnableVertexAttribArray(0);
            glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)0);
            glBindBuffer(GL_ARRAY_BUFFER, 0);
            glBindVertexArray(0);

            base_shader = new Shader("../../../../shaders/default_vertex.vert", "../../../../shaders/default_fragment.frag");
        }

        void Deinit() {
            delete base_shader;
            glDeleteVertexArrays(1, &quad);
        }

        void AddDrawObject(const DrawInfo& info) {
            render_queue.push(info);
        }

        glm::mat4 DrawInfoToMatrix(const DrawInfo& draw_info) {
            glm::mat4 model = glm::mat4(1.0f);
            model = glm::translate(model, draw_info.pos);
            model = glm::rotate(model, glm::radians(draw_info.rot.x), glm::vec3(1.0f, 0.0f, 0.0f));
            model = glm::rotate(model, glm::radians(draw_info.rot.y), glm::vec3(0.0f, 1.0f, 0.0f));
            model = glm::rotate(model, glm::radians(draw_info.rot.z), glm::vec3(0.0f, 0.0f, 1.0f));
            model = glm::scale(model, draw_info.scale);
            return model;
        }

        uint32_t GetTextureFromDrawInfo(const DrawInfo& info) {
            if (strcmp("", info.texture_path)) {
                // Texture source has been set
                return Resource::GetTexture(info.texture_name, info.texture_path);
            }
            else {
                // Texture source not set, return blank texture
                return 0;
            }
        }

        void Render() {
            glClear(GL_COLOR_BUFFER_BIT);

            base_shader->Use();
            base_shader->UMat4("projection", glm::ortho(0.0f, 1920.0f, 1080.0f, 0.0f, -1.0f, 1.0f));

            while (render_queue.size() > 0) {
                const DrawInfo& sprite_info = render_queue.front();
                base_shader->UMat4("model", DrawInfoToMatrix(sprite_info));
                base_shader->U3f("color_override", sprite_info.color);
                uint32_t tex = GetTextureFromDrawInfo(sprite_info);
                glBindTextureUnit(0, tex);
                glBindVertexArray(quad);
                glDrawArrays(GL_TRIANGLES, 0, 6);
                render_queue.pop();
            }
        }
    }
}