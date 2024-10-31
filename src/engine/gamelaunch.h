#ifndef GAMELAUNCH_H
#define GAMELAUNCH_H

#include "RenderWindow.h"
#include "Events.h"
#include "../graphics/Shader.h"

#pragma once

class gamelaunch
{
public:
    gamelaunch();
    ~gamelaunch();

    int launch();

private:
    Events* event = nullptr;
    RenderWindow* render_w = nullptr;

    int width, height;
};

#endif