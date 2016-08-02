#include "stdafx.h"

void Player::initVAO()
{
    vao->addAttribute(2, "vpos");
    vao->addAttribute(2, "vtexcoord");
    vao->genAttributes();

    vao->generate(6, buStaticDraw);

    struct {
        vec2 pos;
        vec2 tex;
    } data;

    vao->map(baWriteOnly);
    data.pos = vec2(0, 0);
    data.tex = vec2(0, 0);
    vao->addVertex(&data);
    data.pos = vec2(1, 0);
    data.tex = vec2(1, 0);
    vao->addVertex(&data);
    data.pos = vec2(1, 1);
    data.tex = vec2(1, 1);
    vao->addVertex(&data);
    data.pos = vec2(1, 1);
    data.tex = vec2(1, 1);
    vao->addVertex(&data);
    data.pos = vec2(0, 1);
    data.tex = vec2(0, 1);
    vao->addVertex(&data);
    data.pos = vec2(0, 0);
    data.tex = vec2(0, 0);
    vao->addVertex(&data);
    vao->unmap();
}

Player::Player(Game* g)
{
	window = g->getWindow();
	grid = g->getFGGrid();
	keyManager = new KeyManager(window);
    
    vao = new VAO(g->getTextureShader());
    initVAO();
}

Player::~Player()
{
	delete keyManager;
    delete vao;
}

void Player::update(float deltaTime) 
{
	keyManager->update();

	if (keyManager->keyDown(K_UP)) 
		pos.translatePosition(vec2(0, 1.42f * deltaTime));
	
    if (keyManager->keyDown(K_DOWN)) 
        pos.translatePosition(vec2(0, -1.42f * deltaTime));

    if (keyManager->keyDown(K_RIGHT))
        pos.translatePosition(vec2(1.42f * deltaTime, 0));
	
    if (keyManager->keyDown(K_LEFT))
        pos.translatePosition(vec2(-1.42f * deltaTime, 0));

	//cout << pos.getPosition() << endl;
}

void Player::render() {
    vao->render();
}
