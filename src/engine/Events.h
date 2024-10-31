#include "RenderWindow.h"
#ifndef EVENTS_H
#define EVENTS_H

#pragma once
typedef unsigned int uint;

class RenderWindow;
class Events
{
public:
	static bool* _keys;
	static uint* frames;
	static uint current;
    static float deltaX, deltaY, x, y;
	static bool _cursor_locked, _cursor_started;

    // Initialize events system
    int initialize(GLFWwindow * window);

    // Getting events
	void pullEvents();

    // Check key pressed
	bool pressed(int keycode);

    // Check key just pressed
	bool jpressed(int keycode);

    // Check mouse button pressed
	bool clicked(int button);

    // Check mouse buttn just pressed
	bool jclicked(int button);

    // ToggleCursor
	void toggleCursor(RenderWindow* window);

};

#endif