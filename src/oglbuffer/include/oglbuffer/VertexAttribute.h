#pragma once

#include <glad/glad.h>

class VertexAttribute
{
    public:
        VertexAttribute(GLuint index, 
            GLint size, 
            GLenum type, 
            GLsizei stride, 
            const void* offset = (void*)0
        );

        void enable() const;

    private:
        GLuint index;
        GLint size;
        GLenum type; 
        GLsizei stride; 
        const void* offset;
};