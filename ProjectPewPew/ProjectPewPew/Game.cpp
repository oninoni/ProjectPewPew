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
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

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

    glfwSwapInterval(1); // V-Sync off (on is default, but it glitches if you don't call it)

	glEnable(GL_BLEND);
	glBlendFunc(bfsSrcAlpha, bfdOneMinusSrcAlpha);

    return true;
}

void Game::start()
{
	textureMap = new TextureMap();

    textureMap->addTexture("player.png");

    textureMap->addTexture("grass.png");
    textureMap->addTexture("stone.png");
    textureMap->addTexture("stone_sexy.png");
    textureMap->addTexture("stone_bricks.png");
    textureMap->addTexture("wooden_planks.png");

    textureMap->buildPage();
	textureMap->uniform(textureShader, "tex");

    int w, h;
    glfwGetWindowSize(window, &w, &h);
    glUniform1f(textureShader->getUniformLocation("aspect"), (float)w / h);     

	view = new View(textureShader);
	view->setScale(vec2(2 * 64.0f / h, 2 * 64.0f / h));
    view->uniform("view");

	fgGrid = new FGGrid(20, 10, this);
	bgGrid = new BGGrid(20, 10, this);

	player = new Player(this);

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
    view->getPos().setPosition(player->getPos().getPosition());

	fgGrid->update(deltaTime);
	bgGrid->update(deltaTime);
}

void Game::render()
{
	glClear(amColorDepth);
	
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

    srand(GetTickCount());

    start();
}

Game::~Game()
{
	delete player;
	delete bgGrid;
	delete fgGrid;

    delete textureShader;
	delete textureMap;
    delete view;

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

View * Game::getView() {
	return view;
}
