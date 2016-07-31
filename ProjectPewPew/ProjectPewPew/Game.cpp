#include "stdafx.h"

bool Game::initGL()
{
	oldTime = 0;

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
        double time = glfwGetTime();
		double deltaT = oldTime - time;
		oldTime = time;

		update(deltaT);
		render();

		glfwPollEvents();
    }
}

void Game::update(float deltaT)
{

}

void Game::render()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glBegin(GL_TRIANGLES);
		glVertex2d(-1,-1);
		glVertex2d( 1,-1);
		glVertex2d(-1, 1);
	glEnd();

	glfwSwapBuffers(window);
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