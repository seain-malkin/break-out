#version 330 core
layout (location = 0) in vec3 lPosition;
layout (location = 1) in vec2 lTexCoord;

out vec2 textureCoord;

void main()
{
    textureCoord = lTexCoord;
    gl_Position = vec4(lPosition, 1.0);
}