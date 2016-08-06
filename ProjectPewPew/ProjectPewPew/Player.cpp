#include "stdafx.h"

void Player::initVAO()
{
    vao = new VAO(shader);

    vao->generate(6, buStaticDraw);

    struct {
        vec2 pos;
        vec2 tex;
        vec2 minborder;
        vec2 maxborder;
    } data;

    textureMap->setTexture("player");

    data.minborder = textureMap->getMinBorder();
    data.maxborder = textureMap->getMaxBorder();

    vao->map(baWriteOnly);
    data.pos = vec2(0, 0);
    data.tex = textureMap->getTexCoord(vec2(0, 0));
    vao->addVertex(&data);
    data.pos = vec2(1, 0);
    data.tex = textureMap->getTexCoord(vec2(1, 0));
    vao->addVertex(&data);
    data.pos = vec2(1, 1);
    data.tex = textureMap->getTexCoord(vec2(1, 1));
    vao->addVertex(&data);
    data.pos = vec2(1, 1);
    data.tex = textureMap->getTexCoord(vec2(1, 1));
    vao->addVertex(&data);
    data.pos = vec2(0, 1);
    data.tex = textureMap->getTexCoord(vec2(0, 1));
    vao->addVertex(&data);
    data.pos = vec2(0, 0);
    data.tex = textureMap->getTexCoord(vec2(0, 0));
    vao->addVertex(&data);
    vao->unmap();
}

Player::Player(Game* g)
{
	window = g->getWindow();
	grid = g->getFGGrid();
    shader = g->getTextureShader();
	view = g->getView();
	textureMap = g->getTextureMap();
    keyManager = new InputManager(window);
	cursor = new Cursor(g);
    
    pos.setOffset(vec2(-0.5, -0.5));
    pos.setPosLowerLimit(vec2(0.5, 0.5));
    pos.setPosUpperLimit(vec2((float)grid->getSize().x, (float)grid->getSize().y) - vec2(0.5, 0.5));

    initVAO();
}

Player::~Player()
{
	delete keyManager;
    delete vao;
	delete cursor;
}

void Player::update(float deltaTime) 
{
	keyManager->update();
	vec2 dir = vec2(0, 0);

	if (keyManager->keyDown(K_UP))
		dir.y += 1;
	
	if (keyManager->keyDown(K_DOWN))
		dir.y -= 1;

	if (keyManager->keyDown(K_RIGHT))
		dir.x += 1;
	
	if (keyManager->keyDown(K_LEFT))
		dir.x -= 1;

	if (keyManager->keyPressed(K_FIRE_PRI)) {
	}

    if (dir != vec2(0, 0))
	    pos.translatePosition(dir.normalize() * speed * deltaTime);
}

void Player::render() {
    glUniformMatrix3fv(shader->getUniformLocation("model"), 1, blFalse, pos.getMatrix().ptr());
    vao->render();
	cursor->render();
}

Location & Player::getPos()
{
    return pos;
}
