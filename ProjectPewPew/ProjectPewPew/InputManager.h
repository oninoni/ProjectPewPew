#pragma once

enum KeyAction {
	kaUp,
	kaDown,
	kaLeft,
	kaRight,
	kaFirePrimary,
	kaFireSecondary,
	kaReload,

    // add new above
	KA_SIZE
};

class InputManager {
private:
	GLFWwindow* window;
    View* view;

	int keyBinds[KA_SIZE];
	bool keyStateOld[KA_SIZE];
	bool keyState[KA_SIZE];
public:
	InputManager(Game* g);
	~InputManager();

    vec2 getMousePos();
    vec2 getGridMousePos();

	void bindKey(KeyAction keyaction, int keyID);
    void bindDefaults();

	void update();

	bool keyPressed(KeyAction keyaction);
	bool keyReleased(KeyAction keyaction);
	bool keyDown(KeyAction keyaction);
	bool keyUp(KeyAction keyaction);
};

