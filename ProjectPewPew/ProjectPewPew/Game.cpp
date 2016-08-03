#include "stdafx.h"

bool Game::initShader()
{
    textureShader = new Shader;
    return textureShader->loadVertFragShader("texture");
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

    glfwSwapInterval(1); // V-Sync on (on is default, but it glitches if you don't call it)

    return true;
}

void Game::start()
{
	textureMap = new TextureMap();

    textureMap->addTexture("grass.png");
	textureMap->buildPage();
	textureMap->uniform(*textureShader, "tex");

    int w, h;
    glfwGetWindowSize(window, &w, &h);
    glUniform1f(textureShader->getUniformLocation("aspect"), (float)w / h);

	fgGrid = new FGGrid(10, 10, this);
	bgGrid = new BGGrid(10, 10, this);

	player = new Player(this);

    view = new View(textureShader);
    view->setScale(vec2(0.2f, 0.2f));
    view->uniform("view");

    runTime = 0;
    oldTime = (float)glfwGetTime();

    while (!glfwWindowShouldClose(window))
    {
		update();

        view->render();
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
	
	bgGrid->render();
	fgGrid->render();

    player->render();

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

    delete textureShader;
	delete textureMap;

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

GLFWwindow * Game::getWindow() {
	return window;
}

FGGrid * Game::getFGGrid() {
	return fgGrid;
}

BGGrid * Game::getBGGrid() {
	return bgGrid;
}

Player * Game::getPlayer() {
	return player;
}

Shader * Game::getTextureShader()
{
    return textureShader;
}

TextureMap * Game::getTextureMap() {
	return textureMap;
}
