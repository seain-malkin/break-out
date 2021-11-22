#include <iostream>

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <glad/glad.h>

#include <oglbuffer/ObjectBuffer.h>
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
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	GLFWwindow *window = glfwCreateWindow(600, 600, "Break Out", NULL, NULL);

	if (window == NULL)	
	{
		std::cout << "Failed to create window." << std::endl;
		return 1;
	}

	glfwMakeContextCurrent(window);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		glfwTerminate();
		std::cout << "Failed to load glad." << std::endl;
		return 2;
	}

	unsigned int vertexBuffer, texCoordBuffer, indiceBuffer, vao;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);
	glGenBuffers(1, &vertexBuffer);
	glGenBuffers(1, &texCoordBuffer);
	glGenBuffers(1, &indiceBuffer);

	glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	glBindBuffer(GL_ARRAY_BUFFER, texCoordBuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(texCoords), texCoords, GL_STATIC_DRAW);

	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(1);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indiceBuffer);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	glBindVertexArray(0);

	Texture catalina{ "assets/texture/catalina.png" };
	catalina.generate();

	Shader basicShader{ "assets/shader/basic.3.3.vs", "assets/shader/basic.3.3.fs" };

	glEnable(GL_DEPTH_TEST);

	while (!glfwWindowShouldClose(window))
	{
		glfwPollEvents();

		glClearColor(0.0f, 0.0f, 0.1f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		basicShader.bind();
		catalina.bind();
		glBindVertexArray(vao);
		glDrawElements(GL_TRIANGLES, sizeof(indices) / sizeof(unsigned int), GL_UNSIGNED_INT, 0);

		glfwSwapBuffers(window);
	}

	glDeleteBuffers(1, &vertexBuffer);
	glDeleteTextures(1, &texCoordBuffer);
	glDeleteBuffers(1, &indiceBuffer);
	glDeleteVertexArrays(1, &vao);

	glfwTerminate();
	
	return 0;
}