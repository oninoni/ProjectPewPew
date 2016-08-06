#include "stdafx.h"

InputManager::InputManager(Game* g) 
{
	window = g->getWindow();
    view = g->getView();

    bindDefaults();	
}

InputManager::~InputManager() 
{
}

vec2 InputManager::getMousePos()
{
    // sry wollte es testen und habs schnell selbst geschrieben...
    // du kannst es aber noch besser machen
    // ich würds machen, dass man ne möglichkeit hat rauszufinden ob sich der cursor bewegt hat
    // dann muss das laser-VAO nicht jeden frame geupdated werden
    double x, y;
    glfwGetCursorPos(window, &x, &y);
    int w, h;
    glfwGetWindowSize(window, &w, &h);
    return vec2((float)x / h * 2 - (float)w/h, 1 - (float)y / h * 2);
}

vec2 InputManager::getGridMousePos()
{
    return view->getInvMatrix() * getMousePos();
}

void InputManager::bindKey(KeyAction keycode, int keyID) 
{
	keyBinds[keycode] = keyID;
    keyState[keycode] = false;
	keyStateOld[keycode] = false;
}

void InputManager::bindDefaults()
{
    bindKey(kaUp, GLFW_KEY_W);
    bindKey(kaLeft, GLFW_KEY_A);
    bindKey(kaDown, GLFW_KEY_S);
    bindKey(kaRight, GLFW_KEY_D);
    bindKey(kaFirePrimary, GLFW_MOUSE_BUTTON_LEFT);
    bindKey(kaFireSecondary, GLFW_MOUSE_BUTTON_RIGHT);
    bindKey(kaReload, GLFW_KEY_R);
}

void InputManager::update() 
{
	for (int i = 0; i < KA_SIZE; i++) 
    {
		keyStateOld[i] = keyState[i];
		keyState[i] = glfwGetKey(window, keyBinds[i]) == 1 || glfwGetMouseButton(window, keyBinds[i]) == 1;
	}
}

bool InputManager::keyPressed(KeyAction keycode) 
{
	return keyState[keycode] && !keyStateOld[keycode];
}

bool InputManager::keyReleased(KeyAction keycode) 
{
	return !keyState[keycode] && keyStateOld[keycode];
}

bool InputManager::keyDown(KeyAction keycode) 
{
	return keyState[keycode];
}

bool InputManager::keyUp(KeyAction keycode)
{
	return !keyState[keycode];
}
