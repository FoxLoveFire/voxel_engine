#include "Events.h"
#include <GLFW/glfw3.h>
#include <string.h>

#define _MOUSE_BUTTONS 1024

bool* Events::_keys;
uint* Events::frames;
uint Events::current = 0;
float Events::deltaX = 0.0f;
float Events::deltaY = 0.0f;
float Events::x = 0.0f;
float Events::y = 0.0f;
bool Events::_cursor_locked = false;
bool Events::_cursor_started = false;

void cursor_position_callback(GLFWwindow* window, double xpos, double ypos) {
	if (Events::_cursor_started) {
		Events::deltaX += xpos - Events::x;
		Events::deltaY += ypos - Events::y;
	}
	else {
		Events::_cursor_started = true;
	}
	Events::x = xpos;
	Events::y = ypos;
}

void mouse_button_callback(GLFWwindow* window, int button, int action, int mode) {
	if (action == GLFW_PRESS) {
		Events::_keys[_MOUSE_BUTTONS + button] = true;
		Events::frames[_MOUSE_BUTTONS + button] = Events::current;
	}
	else if (action == GLFW_RELEASE) {
		Events::_keys[_MOUSE_BUTTONS + button] = false;
		Events::frames[_MOUSE_BUTTONS + button] = Events::current;
	}
}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode) {
	if (action == GLFW_PRESS) {
		Events::_keys[key] = true;
		Events::frames[key] = Events::current;
	}
	else if (action == GLFW_RELEASE) {
		Events::_keys[key] = false;
		Events::frames[key] = Events::current;
	}
}
void window_size_callback(GLFWwindow* window, int width, int heigth) 
{
	glViewport(0, 0, width, heigth);
}

int Events::initialize(GLFWwindow* window) {
	_keys = new bool[1032];
	frames = new uint[1032];

	memset(_keys, false, 1032 * sizeof(bool));
	memset(frames, 0, 1032 * sizeof(uint));

	glfwSetKeyCallback(window,key_callback);
	glfwSetMouseButtonCallback(window, mouse_button_callback);
	glfwSetCursorPosCallback(window, cursor_position_callback);
	glfwSetWindowSizeCallback(window, window_size_callback);
	return 0;
}

bool Events::pressed(int keycode) {
	if (keycode < 0 || keycode >= _MOUSE_BUTTONS)
		return false;
	return _keys[keycode];
}

bool Events::jpressed(int keycode) {
	if (keycode < 0 || keycode >= _MOUSE_BUTTONS)
		return false;
	return _keys[keycode] && frames[keycode] == current;
}

bool Events::clicked(int button) {
	int index = _MOUSE_BUTTONS + button;
	return _keys[index];
}

bool Events::jclicked(int button) {
	int index = _MOUSE_BUTTONS + button;
	return _keys[index] && frames[index] == current;
}	

void Events::toggleCursor(RenderWindow* window)
{
	_cursor_locked = !_cursor_locked;
	window->setCursorMode(_cursor_locked ? GLFW_CURSOR_DISABLED : GLFW_CURSOR_NORMAL);
}

void Events::pullEvents() {
	current++;
	deltaX = 0.0f;
	deltaY = 0.0f;
	glfwPollEvents();
}
