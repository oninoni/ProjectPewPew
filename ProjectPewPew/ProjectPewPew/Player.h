#pragma once
class Player
{
private:
	KeyManager* keyManager;

	GLFWwindow* window;

    vec2 pos;

public:
	Player(vec2 pos, GLFWwindow* w);
    Player(float x, float y, GLFWwindow* w);
    ~Player();

	void update(double deltaT);
	void render();
};

