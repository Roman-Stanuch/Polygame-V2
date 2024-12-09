#pragma once

#include <glm/glm.hpp>
#include <string>

namespace Polygame
{
    class Shader
    {
    public:
        unsigned int ID;
        Shader(const char* vertexPath, const char* fragmentPath);
        // sets the current shader as active
        Shader& Use();
        // utility functions
        void    U1f(const char* name, float value, bool useShader = false);
        void    U1i(const char* name, int value, bool useShader = false);
        void    U2f(const char* name, float x, float y, bool useShader = false);
        void    U2f(const char* name, const glm::vec2& value, bool useShader = false);
        void    U3f(const char* name, float x, float y, float z, bool useShader = false);
        void    U3f(const char* name, const glm::vec3& value, bool useShader = false);
        void    U4f(const char* name, float x, float y, float z, float w, bool useShader = false);
        void    U4f(const char* name, const glm::vec4& value, bool useShader = false);
        void    UMat4(const char* name, const glm::mat4& matrix, bool useShader = false);
    private:
        // checks if compilation or linking failed and if so, print the error logs
        void    checkCompileErrors(unsigned int object, std::string type);
    };
}