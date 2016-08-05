#include "stdafx.h"

InputManager::InputManager(GLFWwindow* w) {

	window = w;
	bindKey(K_UP   , GLFW_KEY_W);
    bindKey(K_LEFT , GLFW_KEY_A); 
    bindKey(K_DOWN , GLFW_KEY_S);
	bindKey(K_RIGHT, GLFW_KEY_D);
	bindKey(K_FIRE_PRI, GLFW_MOUSE_BUTTON_LEFT);
	bindKey(K_FIRE_SEC, GLFW_MOUSE_BUTTON_RIGHT);
	bindKey(K_RELOAD, GLFW_KEY_R);
}

InputManager::~InputManager() {

}

void InputManager::bindKey(KeyCodes keycode, int keyID) {
	keyBinds[keycode] = keyID;
    keyState[keycode] = false;
	keyStateOld[keycode] = false;
}

void InputManager::update() {
	for (int i = 0; i < K_SIZE; i++) {
		keyStateOld[i] = keyState[i];
		keyState[i] = glfwGetKey(window, keyBinds[i]) == 1 || glfwGetMouseButton(window, keyBinds[i]) == 1;
	}
}

bool InputManager::keyPressed(KeyCodes keycode) {
	return keyState[keycode] && !keyStateOld[keycode];
}

bool InputManager::keyReleased(KeyCodes keycode) {
	return !keyState[keycode] && keyStateOld[keycode];
}

bool InputManager::keyDown(KeyCodes keycode) {
	return keyState[keycode];
}

bool InputManager::keyUp(KeyCodes keycode) {
	return !keyState[keycode];
}
