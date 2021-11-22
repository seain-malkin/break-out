#pragma once

#include <glad/glad.h>

class ObjectBuffer
{
public:
	ObjectBuffer(GLenum target = GL_ARRAY_BUFFER);
	~ObjectBuffer();

	void allocate(GLsizeiptr size, const void* data, GLenum usage = GL_STATIC_DRAW);

	void bind() const;
	void unbind() const;

	GLenum getTarget() const;

private:
	GLuint glid;
	GLenum target;
};