#pragma once

enum KeyCodes {
	K_UP,
	K_DOWN,
	K_LEFT,
	K_RIGHT,
	K_FIRE_PRI,
	K_FIRE_SEC,
	K_RELOAD,
	K_SIZE
};

class InputManager {
private:
	GLFWwindow* window;

	int keyBinds[K_SIZE];
	bool keyStateOld[K_SIZE];
	bool keyState[K_SIZE];
public:
	InputManager(GLFWwindow* w);
	~InputManager();

	void bindKey(KeyCodes keycode, int keyID);

	void update();

	bool keyPressed(KeyCodes keycode);
	bool keyReleased(KeyCodes keycode);
	bool keyDown(KeyCodes keycode);
	bool keyUp(KeyCodes keycode);
};

