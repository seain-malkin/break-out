#include <oglbuffer/ObjectBuffer.h>

ObjectBuffer::ObjectBuffer(GLenum target)
: glid(0), target(target) 
{
    glGenBuffers(1, &glid);
}

ObjectBuffer::~ObjectBuffer()
{
    glDeleteBuffers(1, &glid);
}

void ObjectBuffer::allocate(GLsizeiptr size, const void* data, GLenum usage)
{
    glBindBuffer(target, glid);
    glBufferData(target, size, data, usage);
}

void ObjectBuffer::bind() const
{
    glBindBuffer(target, glid);
}

void ObjectBuffer::unbind() const
{
    glBindBuffer(target, 0);
}

GLenum ObjectBuffer::getTarget() const { return target; }