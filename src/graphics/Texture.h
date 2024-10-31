#ifndef TEXTURE_H
#define TEXTURE_H

#pragma once

class Texture
{
public:
	unsigned int id;
	int width, height;
    Texture(unsigned int id, int width, int height);

    void bind();
    ~Texture();

private:

};

extern Texture* load_texture(const char* filename);

#endif