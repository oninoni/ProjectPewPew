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

    //vector<Entity> entitys

    bool initGL();
    void start();

public:
    Game(int* argc, char** argv);
    ~Game();
};

