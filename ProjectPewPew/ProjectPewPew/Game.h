#pragma once

class Game
{
private:
    GLFWwindow* window;

	TextureMap* textureMap;

    int* argc;
    char** argv;

    FGGrid* fgGrid;
    BGGrid* bgGrid;

    Player* player;
    
    View* view;

	float oldTime;
    float deltaTime;
    float runTime;

    Shader* textureShader;
	Shader* laserShader;

    //std::vector<Entity> entitys;

    bool initTextureShader();
	bool initLaserShader();

    bool initGL();
    void start();

    void updateDeltaTime();

	void update();
	void render();

public:
	Game(int* argc, char** argv);
	~Game();

	float getDeltaTime();
    float getRunTime();

	GLFWwindow* getWindow();
	FGGrid* getFGGrid();
	BGGrid* getBGGrid();
	Player* getPlayer();
	TextureMap* getTextureMap();
	View* getView();

	Shader* getLaserShader();
	Shader* getTextureShader();
};

