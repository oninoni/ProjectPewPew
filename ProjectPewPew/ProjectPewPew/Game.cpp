#include "stdafx.h"

bool Game::initGL()
{
    if (!glfwInit())
    {
        std::cout << "OpenGL failed. You suck!" << std::endl;
        return false;
    }
      
    window = glfwCreateWindow(1280, 720, "Project PewPew", NULL, NULL);
   
    if (!window)
    {
        std::cout << "Window could not be created! You suck!" << std::endl;
        return false;
    }

    glfwMakeContextCurrent(window);

    glClearColor(0, 0, 0, 0);

    return true;
}

void Game::start()
{
    while (!glfwWindowShouldClose(window))
    {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // update
        // render

        glfwSwapBuffers(window);

        glfwPollEvents();
    }
}

Game::Game(int* argc, char** argv)
{
    std::cout << "Game started!" << std::endl;

    this->argc = argc;
    this->argv = argv;

    if (!initGL())
        return;

    start();
}             

Game::~Game()
{
    glfwTerminate();
    std::cout << "Game stopped!" << std::endl;
}