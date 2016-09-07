#pragma once

#define IM_SCROLL_UP -2
#define IM_SCROLL_DOWN -1

enum KeyAction {
	kaUp,
	kaDown,
	kaLeft,
	kaRight,
	kaFirePrimary,
	kaFireSecondary,
	kaReload,
    kaWeaponSwitchUp,
    kaWeaponSwitchDown,

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

    int scrollData[2];

    static void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);

    int getScroll(int keyCode);
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

    int* getScrollData();
};

