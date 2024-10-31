#include <iostream>

#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "engine/RenderWindow.h"
#include "engine/Events.h"
#include "engine/gamelaunch.h"

#define WIDTH 1280
#define HEIGHT 720

int main()
{
    gamelaunch* game_launch = new gamelaunch();
    game_launch->launch();
}