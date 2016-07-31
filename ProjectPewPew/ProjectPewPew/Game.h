#pragma once
class Game
{
private:
    GLFWwindow* window;

    int* argc;
    char** argv;

    FGGrid fgGrid;
    BGGrid bgGrid;

    Player player;

	double oldTime;
    double deltaTime;
    double runTime;

    Shader* testShader;

    //std::vector<Entity> entitys;

    bool initShader();

    bool initGL();
    void start();

    void updateDeltaTime();

	void update();
	void render();

public:
    Game(int* argc, char** argv);
    ~Game();

    double getDeltaTime();
    double getRunTime();
};

