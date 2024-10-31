#include "RenderWindow.h"

RenderWindow::RenderWindow()
{
    window = nullptr;

}

void ErrorCallback(int, const char* err_str)
{
    std::cout << "GLFW Error: " << err_str << std::endl;
}

void RenderWindow::initialize(const char* title, int width, int height) 
{
    
    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW" << std::endl;
        exit(1);
    }
    glfwSetErrorCallback(ErrorCallback);

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, GL_TRUE);

    window = glfwCreateWindow(width, height, title, nullptr, nullptr);
    if (window == nullptr) {
        std::cerr << "Failed to create GLFW Window" << std::endl;
        glfwTerminate();
        exit(1);
    }

    glfwMakeContextCurrent(window);

    glewExperimental = GL_TRUE;
    if (glewInit() != GLEW_OK) {
        std::cerr << "Failed to initialize GLEW" << std::endl;
        exit(1);
    }

    glViewport(0, 0, width, height);

    this->height = height;
    this->width = width;
}

void RenderWindow::terminate() 
{
    glfwTerminate();
}

std::vector <int> RenderWindow::get_size()
{
    return {width, height};
}

bool RenderWindow::isShouldClose()
{
    return glfwWindowShouldClose(window);
}

void RenderWindow::swapBuffers()
{
    glfwSwapBuffers(window);
}

void RenderWindow::setCursorMode(int mode)
{
    glfwSetInputMode(window, GLFW_CURSOR, mode);
}

void RenderWindow::setShouldClose(bool flag)
{   
    glfwSetWindowShouldClose(window, flag);
}

GLFWwindow* RenderWindow::get_window() 
{
    return window;
}

RenderWindow::~RenderWindow()
{

}