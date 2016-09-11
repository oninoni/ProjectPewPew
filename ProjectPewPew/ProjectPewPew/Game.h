#pragma once

static int* argcS;
static char** argvS;

class Game
{
private:
    Game(int* argc, char** argv);
    ~Game();

    GLFWwindow* window;

	TextureMap* textureMap;

    int* argc;
    char** argv;

    FGGrid* fgGrid;
    BGGrid* bgGrid;

    EntityManager* entityManager;

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

    static Game* getInstance(int* argc, char** argv);
    static Game* getInstance();

    float getDeltaTime();
    float getRunTime();

	GLFWwindow* getWindow();
	FGGrid* getFGGrid();
	BGGrid* getBGGrid();
	Player* getPlayer();
	TextureMap* getTextureMap();
	View* getView();

    EntityManager* getEntityManager();

	Shader* getLaserShader();
	Shader* getTextureShader();
};

