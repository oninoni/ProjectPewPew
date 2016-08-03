#pragma once

class Player
{
private:
	KeyManager* keyManager;

	GLFWwindow* window;
	FGGrid* grid;

    Location pos;

    Shader* shader;
    VAO* vao;

    void initVAO();

public:
	Player(Game* g);
    ~Player();

	void update(float deltaT);
	void render();
};

