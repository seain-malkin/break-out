#pragma once

#include <vector>
#include <glad/glad.h>
#include <oglbuffer/ObjectBuffer.h>
#include <oglbuffer/VertexAttribute.h>

class VertexArray
{
    private:
        GLuint glid;

    public:
        VertexArray();
        ~VertexArray();

        /** Binds to opengl state **/
        void bind() const;
        void unbind() const;

        void addBuffer(ObjectBuffer buffer, VertexAttribute attrib);

        void addBuffer(
            ObjectBuffer buffer, 
            const std::vector<VertexAttribute> attribs
        );

};