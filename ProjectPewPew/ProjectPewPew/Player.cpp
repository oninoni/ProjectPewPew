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

    input = new InputManager(g);
	cursor = new Cursor(g, this);

	gun = new Gun(g, this);
    
    pos.setOffset(vec2(-0.5, -0.5));
    pos.setPosLowerLimit(vec2(0.5, 0.5));
	pos.setPosUpperLimit(vec2((float)grid->getSize().x, (float)grid->getSize().y) - vec2(0.5, 0.5));

    initVAO();
}

Player::~Player()
{
	delete input;
    delete vao;
	delete cursor;
	delete gun;
}

void Player::update(float deltaTime) 
{
	input->update();
	cursor->update(deltaTime);
    pos.setRotation(cursor->getDirection().getAngle());

	vec2 dir = vec2(0, 0);

	if (input->keyDown(kaUp))
		dir.y += 1;
	
	if (input->keyDown(kaDown))
		dir.y -= 1;

	if (input->keyDown(kaRight))
		dir.x += 1;
	
	if (input->keyDown(kaLeft))
		dir.x -= 1;

	if (input->keyPressed(kaFirePrimary)) {
	}

    if (dir != vec2(0, 0))
	    pos.translatePosition(dir.normalize() * speed * deltaTime);

	gun->update(deltaTime);
}

void Player::render() 
{
	cursor->render();
	gun->render();
    vao->getPos() = pos;
    vao->render();
}

InputManager * Player::getInputManager()
{
    return input;
}

Location & Player::getPos()
{
    return pos;
}
