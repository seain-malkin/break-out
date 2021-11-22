#include <oglengine/Engine.h>

#include <iostream>
#include <glad/glad.h>

Engine::Engine()
: window(nullptr)
{
    glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
}

Engine::~Engine() 
{
    glfwTerminate();
}

void Engine::start()
{
    window = glfwCreateWindow(600, 600, "Break Out", NULL, NULL);
    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		glfwTerminate();
		std::cout << "Failed to load glad." << std::endl;
	}
}