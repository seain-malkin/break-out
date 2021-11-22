#include <iostream>

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <glad/glad.h>

#include <oglengine/Engine.h>
#include <oglbuffer/ObjectBuffer.h>
#include <oglbuffer/VertexArray.h>
#include <oglbuffer/VertexAttribute.h>
#include <oglasset/Shader.h>
#include <oglasset/Texture.h>

#include "Config.h"

struct Vertex
{
	float x;
	float y;
	float z;
};

struct TextureCoord
{
	float s;
	float t;
};

Vertex vertices[] = {
	{-0.5, -0.5, 0.0}, 
	{-0.5, 0.5, 0.0}, 
	{0.5, 0.5, 0.0}, 
	{0.5, -0.5, 0.0}
};

TextureCoord texCoords[] = {
	{0.0, 0.0}, {0.0, 1.0}, {1.0, 1.0}, {1.0, 0.0}
};

unsigned int indices[] = { 0, 1, 2, 0, 2, 3 };

int main()
{
	Engine engine;

	engine.start();

	VertexArray vertexArray;
	ObjectBuffer vertexBuffer, stBuffer, indiceBuffer{ GL_ELEMENT_ARRAY_BUFFER };
	
	vertexBuffer.allocate(sizeof(vertices), vertices);
	stBuffer.allocate(sizeof(texCoords), texCoords);
	indiceBuffer.allocate(sizeof(indices), indices);

	vertexArray.addBuffer(vertexBuffer, { 0, 3, GL_FLOAT, 3 * sizeof(float) });
	vertexArray.addBuffer(stBuffer, { 1, 2, GL_FLOAT, 2 * sizeof(float) });
	vertexArray.addBuffer(indiceBuffer);

	Texture container{ "assets/texture/container2.png" };
	container.generate();

	Shader basicShader{ "assets/shader/basic.3.3.vs", "assets/shader/basic.3.3.fs" };

	glEnable(GL_DEPTH_TEST);

	while (!glfwWindowShouldClose(engine.window))
	{
		glfwPollEvents();

		glClearColor(0.0f, 0.0f, 0.1f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		basicShader.bind();
		container.bind();
		vertexArray.bind();
		glDrawElements(GL_TRIANGLES, sizeof(indices) / sizeof(unsigned int), GL_UNSIGNED_INT, 0);

		glfwSwapBuffers(engine.window);
	}
	
	return 0;
}