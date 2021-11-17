#version 330 core
layout (location = 0) in vec3 lPosition;

out vec4 vertexColor;

void main()
{
    vertexColor = vec4(lPosition, 1.0);
    gl_Position = vec4(lPosition, 1.0);
}