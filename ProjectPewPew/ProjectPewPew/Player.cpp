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

bool Player::checkCollision(vec2 pos) {
	ivec2 size = grid->getSize();
	Tile tile = grid->getTileAt(pos);
	return tile.isSolid();
}

Player::Player(Game* g)
{
	window = g->getWindow();
	grid = g->getFGGrid();
    shader = g->getTextureShader();
	view = g->getView();
	textureMap = g->getTextureMap();

    input = InputManager::getInstance(g);
	cursor = new Cursor(g, this, grid);

	gun = new Gun(g, this);
    
    pos.setOffset(vec2(-0.5, -0.5));
    pos.setPosLowerLimit(vec2(0.5, 0.5));
	pos.setPosUpperLimit(vec2((float)grid->getSize().x, (float)grid->getSize().y) - vec2(0.5, 0.5));

    initVAO();
}

Player::~Player()
{
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

	if (input->keyDown(kaUp)    && !checkCollision(pos.getPosition() + vec2(0,  speed * deltaTime)))
		dir.y += 1;
	
	if (input->keyDown(kaDown)  && !checkCollision(pos.getPosition() + vec2(0, -speed * deltaTime)))
		dir.y -= 1;

	if (input->keyDown(kaRight) && !checkCollision(pos.getPosition() + vec2( speed * deltaTime, 0)))
		dir.x += 1;
	
	if (input->keyDown(kaLeft)  && !checkCollision(pos.getPosition() + vec2(-speed * deltaTime, 0)))
		dir.x -= 1;

	if (input->keyPressed(kaFirePrimary)) {
	}

    if (dir != vec2(0, 0))
	    pos.translatePosition(dir.normalize() * speed * deltaTime);

	gun->update(deltaTime);

    //cout << "X: " << pos.getPosition().x << " /Y: " << pos.getPosition().y << endl;
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