#version 460 core
in vec2 TexCoords;
out vec4 color;

layout(binding = 0) uniform sampler2D sprite;

void main()
{    
    color = texture(sprite, TexCoords);
}