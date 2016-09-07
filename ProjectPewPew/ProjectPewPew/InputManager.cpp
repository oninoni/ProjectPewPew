#include "stdafx.h"

void InputManager::scroll_callback(GLFWwindow * window, double xoffset, double yoffset) {
	cout << "X: " << xoffset << ", Y: " << yoffset << endl;
	Game* game = (Game*)glfwGetWindowUserPointer(window);
	if (yoffset != 0) {
		if (yoffset > 0) {
			game->getPlayer()->getInputManager()->getScrollData()[IM_SCROLL_UP + 2] = (int)yoffset;
		}
		else {
			game->getPlayer()->getInputManager()->getScrollData()[IM_SCROLL_DOWN + 2] = (int)-yoffset;
		}
	}
}

int InputManager::getScroll(int keyCode) {
    if (keyCode == IM_SCROLL_DOWN || keyCode == IM_SCROLL_UP) {
		int k = keyCode + 2;
		int result = scrollData[k];
		scrollData[k] = 0;
		return result;
    }
    return -1;
}

InputManager::InputManager(Game* g)
{	
	window = g->getWindow();
    view = g->getView();

    glfwSetScrollCallback(window, scroll_callback);

    bindDefaults();
}

InputManager::~InputManager() 
{
}

vec2 InputManager::getMousePos()
{
    double x, y;
    glfwGetCursorPos(window, &x, &y);
    int w, h;
    glfwGetWindowSize(window, &w, &h);
    return vec2((float)x / w * 2 - 1, 1 - (float)y / h * 2);
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
	bindKey(kaWeaponSwitchUp, IM_SCROLL_UP);
	bindKey(kaWeaponSwitchDown, IM_SCROLL_DOWN);
}

void InputManager::update() 
{
	for (int i = 0; i < KA_SIZE; i++) 
    {
		keyStateOld[i] = keyState[i];
		keyState[i] = glfwGetKey(window, keyBinds[i]) == 1 || 
					  glfwGetMouseButton(window, keyBinds[i]) == 1 ||
					  getScroll(keyBinds[i]) > 0;
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

int* InputManager::getScrollData() {
    return scrollData;
}
