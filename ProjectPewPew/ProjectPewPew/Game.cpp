#include "stdafx.h"

bool Game::initGL()
{
	oldTime = 0;

    if (!glfwInit())
    {
        cout << "GLFW failed. You suck!" << endl;
        return false;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);

    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_COMPAT_PROFILE);

    if (!(window = glfwCreateWindow(1280, 720, "Project PewPew", NULL, NULL)))
    {
        cout << "Window could not be created! You suck!" << endl;
        return false;
    }

    glfwMakeContextCurrent(window);

    if (glewInit())
    {
        cout << "Glew could not be initilalized. You suck!" << endl;
        return false;
    }

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

void Game::update(double deltaTime)
{
	player.update(deltaTime);

	fgGrid.update(deltaTime);
	bgGrid.update(deltaTime);
}

void Game::render()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	glfwSwapBuffers(window);
}

Game::Game(int* argc, char** argv)
{
    cout << "Game started!" << endl;

    this->argc = argc;
    this->argv = argv;

    if (!initGL())
        return;

    Shader test;
    test.loadVertFragShader("test");

    start();
}

Game::~Game()
{
    glfwTerminate();
    cout << "Game stopped!" << endl;
}