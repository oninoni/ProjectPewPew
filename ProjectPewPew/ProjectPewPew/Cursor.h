#pragma once
class Cursor {
private:
	Player* player;
    InputManager* input;

	vec2 pos;       

	VAO* vaoLaser;
	VAO* vaoCrosshair;

	GLFWwindow* window;
public:
	Cursor(Game* g, Player* player); 
    // can't get player out of game because called in constructor of Player
    // and there game doesn't now about player yet...
	~Cursor();

	void updateLaser();
	void update(float deltaTime);
	void render();
};
