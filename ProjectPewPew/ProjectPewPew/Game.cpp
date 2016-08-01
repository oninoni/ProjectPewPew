#include "stdafx.h"

bool Game::initShader()
{
    testShader = new Shader;
    return testShader->loadVertFragShader("test");
}

bool Game::initGL()
{
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
    TextureMap texmap;
    texmap.addTexture("grass.png");
    texmap.buildPage();
    texmap.uniform(*testShader, "tex");

    int w, h;
    glfwGetWindowSize(window, &w, &h);
    glUniform1f(testShader->getUniformLocation("aspect"), (float)w / h);

	fgGrid = new FGGrid(10, 10);
	bgGrid = new BGGrid(10, 10);

	player = new Player(0, 0);

    runTime = 0;
    oldTime = (float)glfwGetTime();

    while (!glfwWindowShouldClose(window))
    {
		update();
		render();

		glfwPollEvents();
    }
}

void Game::updateDeltaTime()
{
    float time = (float)glfwGetTime();
    deltaTime = time - oldTime;
    oldTime = time;

    runTime += deltaTime;
}

void Game::update()
{
    updateDeltaTime();

	player->update(deltaTime);

	fgGrid->update(deltaTime);
	bgGrid->update(deltaTime);
}

void Game::render()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
    glBegin(rmTriangles);

    glTexCoord2f(0, 0);
    glVertex2f(-0.5, -0.5);
    glTexCoord2f(1, 0);
    glVertex2f(0.5, -0.5);
    glTexCoord2f(1, 1);
    glVertex2f(0.5, 0.5);
    glTexCoord2f(1, 1);
    glVertex2f(0.5, 0.5);
    glTexCoord2f(0, 1);
    glVertex2f(-0.5, 0.5);
    glTexCoord2f(0, 0);
    glVertex2f(-0.5, -0.5);


    glEnd();

	glfwSwapBuffers(window);
}

Game::Game(int* argc, char** argv)
{
    cout << "Game started!" << endl;

    this->argc = argc;
    this->argv = argv;

    if (!initGL())
        return;

    if (!initShader())
        return;

    start();
}

Game::~Game()
{
	delete player;
	delete bgGrid;
	delete fgGrid;

    delete testShader;

    glfwTerminate();
    cout << "Game stopped!" << endl;
}

float Game::getDeltaTime()
{
    return deltaTime;
}

float Game::getRunTime()
{
    return runTime;
}
