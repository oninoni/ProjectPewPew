#pragma once

class Player
{
private:
	Cursor* cursor;
	InputManager* input;

	GLFWwindow* window;
	FGGrid* grid;

	View* view;
	TextureMap* textureMap;

    Location pos;

    Shader* shader;
    VAO* vao;

	Gun* gun;

    const float speed = 4.2f;

    void initVAO();
	bool checkCollision(vec2 pos);
public:
	Player(Game* g);
    ~Player();

	void update(float deltaT);
	void render();

    InputManager* getInputManager();

    Location & getPos();
};

