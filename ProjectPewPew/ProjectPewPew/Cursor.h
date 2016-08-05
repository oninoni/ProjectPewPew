#pragma once
class Cursor {
private:
	Player* player;

	float xPos, yPos;

	VAO* vaoLaser;
	VAO* vaoTarget;

	GLFWwindow* window;
public:
	Cursor(Game* g);
	~Cursor();

	void render();
};
