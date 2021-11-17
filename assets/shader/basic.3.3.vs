#version 330 core
layout (location = 0) in vec3 lPosition;
layout (location = 1) in vec2 lTexCoord;

out vec4 vertexColor;
out vec2 textureCoord;

void main()
{
    vertexColor = vec4(lPosition, 1.0);
    textureCoord = lTexCoord;
    gl_Position = vec4(lPosition, 1.0);
}