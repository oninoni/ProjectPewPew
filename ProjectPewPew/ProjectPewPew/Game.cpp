#include "stdafx.h"

bool Game::initTextureShader()
{
    textureShader = new Shader;
    if (!textureShader->loadVertFragShader("texture"))
    {
        cout << "Texture Shader not loaded! You suck" << endl;
        return false;
    }
    textureShader->addAttribute(2, "vpos");
    textureShader->addAttribute(2, "vtexcoord");
    textureShader->addAttribute(2, "vminborder");
    textureShader->addAttribute(2, "vmaxborder");
    return true;
}

bool Game::initLaserShader() 
{
	laserShader = new Shader;
    if (!laserShader->loadVertFragShader("laser"))
    {
        cout << "Laser Shader not loaded! You suck" << endl;
        return false;
    }
    laserShader->addAttribute(2, "vpos");
    laserShader->addAttribute(2, "vtexcoord");
    laserShader->addAttribute(4, "vcolor");
    return true;
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
    //if (!(window = glfwCreateWindow(1920, 1080, "Project PewPew", glfwGetPrimaryMonitor(), NULL)))
    {
        cout << "Window could not be created! You suck!" << endl;
        return false;
    }

	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_HIDDEN);

    glfwMakeContextCurrent(window);

    if (glewInit())
    {
        cout << "Glew could not be initilalized. You suck!" << endl;
        return false;
    }

    glfwSwapInterval(0); // V-Sync off (on is default, but it glitches if you don't call it)

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
    textureMap->addTexture("crosshair.png");
	textureMap->addTexture("laser_gun.png");
    textureMap->addTexture("Tint.png");

    textureMap->buildPage();
	textureMap->uniform(textureShader, "tex");

    int w, h;
    glfwGetWindowSize(window, &w, &h);
    float aspect = (float)w / h;
    glUniform1f(textureShader->getUniformLocation("aspect"), 1);     

	view = new View();
    view->addShader(textureShader);
    view->addShader(laserShader);

	view->getPos().setScale(vec2(0.2f, 0.2f));
    view->setAspect(aspect);

	fgGrid = new FGGrid(30, 30, this);
	bgGrid = new BGGrid(30, 30, this);

	fgGrid->init();
	bgGrid->init();

    vec2 scale = view->getPos().getScale();
    vec2 limit = vec2(aspect / scale.x, 1 / scale.y);
    view->getPos().setPosLowerLimit(limit);
    view->getPos().setPosUpperLimit(vec2((float)bgGrid->getSize().x, (float)bgGrid->getSize().y) - limit);

	player = new Player(this);
    player->getPos().setPosition(vec2((float)bgGrid->getSize().x, (float)bgGrid->getSize().y) / 2 + vec2(0.5f, 0.5f));
    view->getPos().setPosition(player->getPos().getPosition());

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
    view->getPos().approachPosition(player->getPos(), 1 - exp(-4.2f * deltaTime));

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

    memset(this, 0, sizeof(Game));

    this->argc = argc;
    this->argv = argv;

    if (!initGL())
        return;

    if (!initTextureShader())
        return;

	if (!initLaserShader())
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
    delete laserShader;

	delete textureMap;
    delete view;

    glfwTerminate();
    cout << "Game stopped!" << endl;
}

Game* Game::getInstance(int * argc, char ** argv) {
    argcS = argc;
    argvS = argv;
    return getInstance();
}

Game* Game::getInstance() {
    static Game game(argcS, argvS);
    return &game;
}

float Game::getDeltaTime()
{
    return deltaTime;
}

float Game::getRunTime()
{
    return runTime;
}

GLFWwindow * Game::getWindow() 
{
	return window;
}

FGGrid * Game::getFGGrid()
{
	return fgGrid;
}

BGGrid * Game::getBGGrid() 
{
	return bgGrid;
}

Player * Game::getPlayer()
{
	return player;
}

Shader * Game::getLaserShader() 
{
	return laserShader;
}

Shader * Game::getTextureShader()
{
    return textureShader;
}

TextureMap * Game::getTextureMap() 
{
	return textureMap;
}

View * Game::getView()
{
	return view;
}