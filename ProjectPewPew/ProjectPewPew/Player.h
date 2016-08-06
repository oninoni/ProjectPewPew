#pragma once

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

    const float speed = 4.2f;

    void initVAO();

public:
	Player(Game* g);
    ~Player();

	void update(float deltaT);
	void render();

    Location & getPos();
};

