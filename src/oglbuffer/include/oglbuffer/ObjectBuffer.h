#pragma once

#include <glad/glad.h>

class ObjectBuffer
{
public:
	ObjectBuffer(GLenum target, 
		GLsizeiptr size, 
		const void* data, 
		GLenum usage = GL_STATIC_DRAW);

	~ObjectBuffer();

	void bind() const;
	void unbind() const;

	GLenum getTarget() const;

private:
	GLuint glid;
	GLenum target;
};