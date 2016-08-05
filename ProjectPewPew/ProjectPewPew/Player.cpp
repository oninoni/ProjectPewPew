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
    data.tex = textureMap->getTexCoord("stone", vec2(0, 0));
    vao->addVertex(&data);
    data.pos = vec2(1, 0);
    data.tex = textureMap->getTexCoord("stone", vec2(1, 0));
    vao->addVertex(&data);
    data.pos = vec2(1, 1);
    data.tex = textureMap->getTexCoord("stone", vec2(1, 1));
    vao->addVertex(&data);
    data.pos = vec2(1, 1);
    data.tex = textureMap->getTexCoord("stone", vec2(1, 1));
    vao->addVertex(&data);
    data.pos = vec2(0, 1);
    data.tex = textureMap->getTexCoord("stone", vec2(0, 1));
    vao->addVertex(&data);
    data.pos = vec2(0, 0);
    data.tex = textureMap->getTexCoord("stone", vec2(0, 0));
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
    keyManager = new KeyManager(window);
    
    //pos.setOffset(vec2(-0.5, -0.5));

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

	if (keyManager->keyDown(K_UP)) {
		float maxTranslation = grid->getSize().y - pos.getPosition().y;
		cout << pos.getPosition().y << endl;
		float translation = maxTranslation < 1.42f * deltaTime ? maxTranslation : 1.42f * deltaTime;
		view->getPos()->translateOffset(vec2(0, translation));
		pos.translatePosition(vec2(0, translation));
	}
	
    if (keyManager->keyDown(K_DOWN)) {
		view->getPos()->translateOffset(vec2(0, -1.42f * deltaTime));
		pos.translatePosition(vec2(0, -1.42f * deltaTime));
	}

	if (keyManager->keyDown(K_RIGHT)) {
		view->getPos()->translateOffset(vec2(1.42f * deltaTime, 0));
		pos.translatePosition(vec2(1.42f * deltaTime, 0));
	}
	
	if (keyManager->keyDown(K_LEFT)) {
		view->getPos()->translateOffset(vec2(-1.42f * deltaTime, 0));
		pos.translatePosition(vec2(-1.42f * deltaTime, 0));
	}

	if (keyManager->keyPressed(K_ZOOM_IN))
		view->setScale(view->getScale() * 1.1f);

	if (keyManager->keyPressed(K_ZOOM_OUT))
		view->setScale(view->getScale() / 1.1f);

	//cout << pos.getPosition() << endl;
}

void Player::render() {
    glUniformMatrix3fv(shader->getUniformLocation("model"), 1, blFalse, pos.getMatrix().ptr());
    vao->render();
}

Location & Player::getPos()
{
    return pos;
}
