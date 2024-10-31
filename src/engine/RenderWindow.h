#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <vector>
#include <iostream>

#ifndef RENDERWINDOW_H
#define RENDERWINDOW_H


#pragma once

class RenderWindow
{
public:
    RenderWindow();
    ~RenderWindow();

    // Initialize Window, title - const *char, int width, int height
    void initialize(const char* title, int width, int height);

    // tetminate 
    void terminate();

    // Get window size, returns std::vector, [0] - width, [1] - height
    std::vector<int> get_size();
    
    // Return glfwWindowShouldClose(window)
    bool isShouldClose();

    void setShouldClose(bool flag);
    
    void swapBuffers();

    void setCursorMode(int mode);

    GLFWwindow* get_window();

private:
    GLFWwindow* window;
    int width, height;
};

#endif