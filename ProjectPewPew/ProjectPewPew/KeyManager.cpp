#include "stdafx.h"

KeyManager::KeyManager(GLFWwindow* w) {
	window = w;

	bindKey(K_UP   , GLFW_KEY_W);
	bindKey(K_DOWN , GLFW_KEY_S);
	bindKey(K_LEFT , GLFW_KEY_A);
	bindKey(K_RIGHT, GLFW_KEY_D);
}

KeyManager::~KeyManager() {

}

void KeyManager::bindKey(KeyCodes keycode, int keyID) {
	keyBinds[keycode] = keyID;
	keyState[keycode] = glfwGetKey(window, keyID);
	keyStateOld[keycode] = keyState[keycode];
}
