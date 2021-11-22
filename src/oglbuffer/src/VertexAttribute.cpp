#include <oglbuffer/VertexAttribute.h>

#include <glad/glad.h>

VertexAttribute::VertexAttribute(
    GLuint index, 
    GLint size, 
    GLenum type, 
    GLsizei stride, 
    const void* offset
    ) : index(index), size(size), type(type), stride(stride), offset(offset)
{}

void VertexAttribute::enable() const
{
    glVertexAttribPointer(index, size, type, GL_FALSE, stride, offset);
    glEnableVertexAttribArray(index);
}