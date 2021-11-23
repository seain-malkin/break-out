#include <oglengine/Engine.h>

#include <iostream>
#include <glad/glad.h>

Engine::Engine(const EngineAttributes &attributes)
: window(nullptr)
{
    glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, attributes.versionMajor);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, attributes.versionMinor);
	glfwWindowHint(GLFW_OPENGL_PROFILE, 	   attributes.profile);
}

Engine::~Engine() 
{
    glfwTerminate();
}

void Engine::launch(char *title, unsigned int width, unsigned int height)
{
	window = glfwCreateWindow(width, height, title, NULL, NULL);
    glfwMakeContextCurrent(window);

	if (window == NULL)
	{
		glfwTerminate();
		std::cout << "Failed to create window." << std::endl;
	}

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		glfwTerminate();
		std::cout << "Failed to load glad." << std::endl;
	}
}