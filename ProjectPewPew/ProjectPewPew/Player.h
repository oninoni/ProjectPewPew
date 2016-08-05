#pragma once

#define SPEED 2

class Player
{
private:
	Cursor* cursor;
	InputManager* keyManager;

	GLFWwindow* window;
	FGGrid* grid;

	View* view;
	TextureMap* textureMap;

    Location pos;

    Shader* shader;
    VAO* vao;

    void initVAO();

public:
	Player(Game* g);
    ~Player();

	void update(float deltaT);
	void render();

    Location & getPos();
};

