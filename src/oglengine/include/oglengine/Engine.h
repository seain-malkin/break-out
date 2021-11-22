#pragma once

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

class Engine
{
    public:
        GLFWwindow *window;
    public:
        Engine();
        ~Engine();

        void start();
};