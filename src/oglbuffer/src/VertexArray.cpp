#include <oglbuffer/VertexArray.h>

VertexArray::VertexArray() : glid(0) 
{
    glGenVertexArrays(1, &glid);
}

VertexArray::~VertexArray()
{
    glDeleteVertexArrays(1, &glid);
}

void VertexArray::bind() const
{
    glBindVertexArray(glid);
}

void VertexArray::unbind() const
{
    glBindVertexArray(0);
}

void VertexArray::addBuffer(ObjectBuffer buffer)
{
    bind();
    buffer.bind();
    unbind();
}

void VertexArray::addBuffer(ObjectBuffer buffer, const VertexAttribute attrib)
{
    bind();
    buffer.bind();
    attrib.enable();
    unbind();
}

void VertexArray::addBuffer(
    ObjectBuffer buffer, 
    const std::vector<VertexAttribute> attribs
)
{
    bind();
    buffer.bind();

    for (const auto &attrib : attribs)
    {
        attrib.enable();
    }
    unbind();
}