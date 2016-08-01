#pragma once

enum KeyCodes {
	K_UP,
	K_DOWN,
	K_LEFT,
	K_RIGHT,
	K_SIZE
};

class KeyManager {
private:
	GLFWwindow* window;

	int keyBinds[K_SIZE];
	bool keyStateOld[K_SIZE];
	bool keyState[K_SIZE];
public:
	KeyManager(GLFWwindow* w);
	~KeyManager();

	void bindKey(KeyCodes keycode, int keyID);

	void update();

	bool keyPressed(KeyCodes keycode);
	bool keyReleased(KeyCodes keycode);
	bool keyDown(KeyCodes keycode);
	bool keyUp(KeyCodes keycode);
};

