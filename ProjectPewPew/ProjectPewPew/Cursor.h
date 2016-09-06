#pragma once
class Cursor {
private:
	Player* player;
    InputManager* input;

    FGGrid* grid;

	vec2 pos;       

	VAO* vaoLaser;
	VAO* vaoCrosshair;

	GLFWwindow* window;
public:
	Cursor(Game* g, Player* player, FGGrid* gr);
    // can't get player out of game because called in constructor of Player
    // and there game doesn't now about player yet...
	~Cursor();

    vec2 getDirection();

	void updateLaser();
	void update(float deltaTime);
	void render();
};
