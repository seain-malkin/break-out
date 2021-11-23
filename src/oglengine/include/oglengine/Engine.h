#pragma once

#include <string>

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

struct EngineAttributes
{
	int versionMajor;
	int versionMinor;
	int profile;
};

class Engine
{
    public:
        GLFWwindow *window;

    public:
        Engine(const EngineAttributes &attributes);
        ~Engine();

        void launch(char *title, unsigned int width, unsigned int height);
};