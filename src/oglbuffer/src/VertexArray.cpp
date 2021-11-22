#include <oglbuffer/VertexArray.h>

VertexArray::VertexArray() : glid(0) 
{
    glGenVertexArrays(1, &glid);
}

VertexArray::~VertexArray()
{
    glDeleteVertexArrays(1, &glid);
}

void VertexArray::addBuffer(ObjectBuffer buffer, const VertexAttribute attrib)
{
    buffer.bind();
    attrib.enable();
}

void VertexArray::addBuffer(
    ObjectBuffer buffer, 
    const std::vector<VertexAttribute> attribs
)
{
    buffer.bind();

    for (const auto &attrib : attribs)
    {
        attrib.enable();
    }
}