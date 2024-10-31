#ifndef SHADERMANAGER_H
#define SHADERMANAGER_H
#include "../engine/RenderWindow.h"
#include "Shader.h"

#pragma once

class ShaderManager
{
public:
    Shader* shader;

    ShaderManager(RenderWindow* window);
    ~ShaderManager();

    int load();
    void run();

private:
    RenderWindow* window;
};

#endif