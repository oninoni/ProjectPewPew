#include "stdafx.h"

KeyManager::KeyManager(GLFWwindow* w) {

	window = w;
	bindKey(K_UP   , GLFW_KEY_W);
    bindKey(K_LEFT , GLFW_KEY_A); 
    bindKey(K_DOWN , GLFW_KEY_S);
	bindKey(K_RIGHT, GLFW_KEY_D);
}

KeyManager::~KeyManager() {

}

void KeyManager::bindKey(KeyCodes keycode, int keyID) {
	keyBinds[keycode] = keyID;
    keyState[keycode] = false;
	keyStateOld[keycode] = false;
}

void KeyManager::update() {
	for (int i = 0; i < K_SIZE; i++) {
		keyStateOld[i] = keyState[i];
		keyState[i] = glfwGetKey(window, keyBinds[i]) == 1;
	}
}

bool KeyManager::keyPressed(KeyCodes keycode) {
	return keyState[keycode] && !keyStateOld[keycode];
}

bool KeyManager::keyReleased(KeyCodes keycode) {
	return !keyState[keycode] && keyStateOld[keycode];
}

bool KeyManager::keyDown(KeyCodes keycode) {
	return keyState[keycode];
}

bool KeyManager::keyUp(KeyCodes keycode) {
	return !keyState[keycode];
}
