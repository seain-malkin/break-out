#pragma once

#include <string>

#include <glad/glad.h>

struct TextureParams
{
    GLenum wrapS;
    GLenum wrapT;
    GLenum minFilter;
    GLenum maxFilter;

    static const TextureParams defaultParams;
};

class Texture
{
    private:
        GLuint glid;
        std::string file;
        TextureParams params;
        unsigned char *data;

    public:
        Texture(std::string file);
        Texture(std::string file, TextureParams params);
        ~Texture();

        /** Loads from file and generates the opengl texture */
        void generate();

        /** Uses supplied params instead but doesn't remember them */
        void generate(TextureParams inParams);

        /** Binds the texture to the shader uniform slot */
        void bind(unsigned int slot = 0) const;

        /** Unbinds the texture from the shader slot */
        void unbind(unsigned int slot = 0) const;

        /** Overwrites the current texture parameters */
        void setParams(TextureParams inParams);

    private:
        void loadFile(bool flip = true);
};