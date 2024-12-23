#version 460 core
in vec2 TexCoords;
out vec4 color;

layout(binding = 0) uniform sampler2D sprite;

uniform vec3 color_override;

void main()
{    
    color = texture(sprite, TexCoords) + vec4(color_override, 0);
}