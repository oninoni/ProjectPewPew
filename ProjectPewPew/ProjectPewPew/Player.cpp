#include "stdafx.h"

void Player::initVAO()
{
    vao = new VAO(shader);

    vao->addAttribute(2, "vpos");
    vao->addAttribute(2, "vtexcoord");
    vao->genAttributes();

    vao->generate(6, buStaticDraw);

    struct {
        vec2 pos;
        vec2 tex;
    } data;

    cout << "Size of data = " << sizeof(data) << endl;

    vao->map(baWriteOnly);
    data.pos = vec2(0, 0);
    data.tex = textureMap->getTexCoord("player", vec2(0, 0));
    vao->addVertex(&data);
    data.pos = vec2(1, 0);
    data.tex = textureMap->getTexCoord("player", vec2(1, 0));
    vao->addVertex(&data);
    data.pos = vec2(1, 1);
    data.tex = textureMap->getTexCoord("player", vec2(1, 1));
    vao->addVertex(&data);
    data.pos = vec2(1, 1);
    data.tex = textureMap->getTexCoord("player", vec2(1, 1));
    vao->addVertex(&data);
    data.pos = vec2(0, 1);
    data.tex = textureMap->getTexCoord("player", vec2(0, 1));
    vao->addVertex(&data);
    data.pos = vec2(0, 0);
    data.tex = textureMap->getTexCoord("player", vec2(0, 0));
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
	ivec2 direction = ivec2(0, 0);

	if (keyManager->keyDown(K_UP))
		direction.y++;
	
	if (keyManager->keyDown(K_DOWN))
		direction.y--;

	if (keyManager->keyDown(K_RIGHT))
		direction.x++;
	
	if (keyManager->keyDown(K_LEFT))
		direction.x--;

	if (keyManager->keyPressed(K_FIRE_PRI)) {
	}

	pos.translatePosition(vec2(direction.x * SPEED * deltaTime / (abs(direction.y) + 1.0f), direction.y * SPEED * deltaTime / (abs(direction.x) + 1.0f)));
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
