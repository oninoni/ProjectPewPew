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
	boolean keyStateOld[K_SIZE];
	boolean keyState[K_SIZE];
public:
	KeyManager(GLFWwindow* w);
	~KeyManager();

	void bindKey(KeyCodes keycode, int keyID);

	void update();

	boolean keyPressed(KeyCodes keycode);
	boolean keyReleased(KeyCodes keycode);
	boolean keyDown(KeyCodes keycode);
	boolean keyUp(KeyCodes keycode);
};

