#include <iostream>

#include <oglasset/Texture.h>
#include <stb/stb_image.h>

const TextureParams TextureParams::defaultParams {
    GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR
};

Texture::Texture(std::string file)
: Texture::Texture(file, TextureParams::defaultParams) {}

Texture::Texture(std::string file, TextureParams params)
: glid(0), file(file), params(params), data(nullptr) {}

Texture::~Texture()
{
    glDeleteTextures(1, &glid);
}

void Texture::generate()
{
    generate(params);
}

void Texture::generate(TextureParams inParams)
{
    glGenTextures(1, &glid);
    loadFile(true);
}

void Texture::bind(unsigned int slot) const
{
    glActiveTexture(GL_TEXTURE0 + slot);
    glBindTexture(GL_TEXTURE_2D, glid);
}

void Texture::unbind(unsigned int slot) const
{
    glActiveTexture(GL_TEXTURE0 + slot);
    glBindTexture(GL_TEXTURE_2D, 0);
}

void Texture::setParams(TextureParams inParams)
{
    params = inParams;
}

void Texture::loadFile(bool flip)
{
    int width, height, components;

    stbi_set_flip_vertically_on_load(flip);

    data = stbi_load(file.c_str(), &width, &height, &components, 0);
    if (!data)
    {
        std::cout << "Failed to load texture: " << file << std::endl;
    }
    else
    {
        GLenum mode = GL_RGB;
        switch (components)
        {
            case 1: mode = GL_RED;
                break;
            case 4: mode = GL_RGBA;
                break; 
        }

        glBindTexture(GL_TEXTURE_2D, glid);
        glTexImage2D(GL_TEXTURE_2D, 0, mode, width, height, 0, mode, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, params.wrapS);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, params.wrapT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, params.minFilter);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, params.maxFilter);

        glBindTexture(GL_TEXTURE_2D, 0);

        stbi_image_free(data);
        data = nullptr;
    }
}