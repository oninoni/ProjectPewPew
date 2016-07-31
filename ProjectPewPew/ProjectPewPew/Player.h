#pragma once
class Player
{
private:
	float xPos;
	float yPos;

	GLFWwindow* window;
public:
    Player(GLFWwindow* w, float x, float y);
    ~Player();

	void update(double deltaT);
	void render();
};

