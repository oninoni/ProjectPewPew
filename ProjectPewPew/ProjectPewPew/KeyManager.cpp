#include "stdafx.h"

KeyManager::KeyManager(GLFWwindow* w) {
	window = w;
	bindKey(K_UP   , GLFW_KEY_W);
    bindKey(K_LEFT, GLFW_KEY_A); 
    bindKey(K_DOWN , GLFW_KEY_S);
	bindKey(K_RIGHT, GLFW_KEY_D);
}

KeyManager::~KeyManager() {

}

void KeyManager::bindKey(KeyCodes keycode, int keyID) {
	keyBinds[keycode] = keyID;
    // Possseidon: I don't thing you have to get the key here... better set it to 0
    //             Then if you hold down a key while it rebinds it still triggers the KeyPressed :3
	keyState[keycode] = glfwGetKey(window, keyID);
	keyStateOld[keycode] = keyState[keycode];
}
