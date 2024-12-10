#include "renderer.h"
#include "shader.h"
#include "resource_manager.h"
#include "glad/glad.h"
#include "GLFW/glfw3.h"

#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"

static uint32_t quad = 0;
static Polygame::Shader* base_shader = nullptr;

namespace Polygame {
    namespace Renderer {
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

        glm::mat4 GetMatrix() {
            glm::mat4 model = glm::mat4(1.0f);
            model = glm::translate(model, glm::vec3(0, 0, 0));
            model = glm::rotate(model, glm::radians(0.f), glm::vec3(1.0f, 0.0f, 0.0f));
            model = glm::rotate(model, glm::radians(0.f), glm::vec3(0.0f, 1.0f, 0.0f));
            model = glm::rotate(model, glm::radians(0.f), glm::vec3(0.0f, 0.0f, 1.0f));
            model = glm::scale(model, glm::vec3(30, 30, 0));
            return model;
        }

        void Render() {
            glClear(GL_COLOR_BUFFER_BIT);

            base_shader->Use();
            base_shader->UMat4("projection", glm::ortho(0.0f, 1920.0f, 1080.0f, 0.0f, -1.0f, 1.0f));
            base_shader->UMat4("model", GetMatrix());
            uint32_t tex = Resource::GetTexture("tex", "album_cover.png");
            glBindTextureUnit(0, tex);
            glBindVertexArray(quad);
            glDrawArrays(GL_TRIANGLES, 0, 6);
        }
    }
}