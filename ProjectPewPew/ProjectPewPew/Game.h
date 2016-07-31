#pragma once
class Game
{
private:
    GLFWwindow* window;

    int* argc;
    char** argv;

    FGGrid* fgGrid;
    BGGrid* bgGrid;

    Player* player;

	double oldTime;

    //std::vector<Entity> entitys

    bool initGL();
    void start();

	void update(double deltaT);
	void render();

public:
    Game(int* argc, char** argv);
    ~Game();
};

