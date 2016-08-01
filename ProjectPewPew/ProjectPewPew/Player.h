#pragma once

class Player
{
private:
	KeyManager* keyManager;

	GLFWwindow* window;
	FGGrid* grid;

    vec2 pos;

public:
	Player(vec2 pos, Game* g);
    Player(float x, float y, Game* g);
    ~Player();

	void update(double deltaT);
	void render();
};

