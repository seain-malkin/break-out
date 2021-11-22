#include <oglbuffer/ObjectBuffer.h>

ObjectBuffer::ObjectBuffer(
    GLenum target, 
    GLsizeiptr size, 
    const void* data, 
    GLenum usage)
: glid(0), target(target) 
{
    glBindBuffer(target, glid);
    glBufferData(target, size, data, usage);
}

ObjectBuffer::~ObjectBuffer()
{
    glDeleteBuffers(1, &glid);
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