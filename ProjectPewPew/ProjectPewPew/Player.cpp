#include "stdafx.h"

Player::Player(float x, float y, Game* g):
	Player(vec2(x, y), g)
{

}

Player::Player(vec2 pos, Game* g)
{
	window = g->getWindow();
	grid = g->getFGGrid();
	keyManager = new KeyManager(window);
    this->pos = pos;
}

Player::~Player()
{
	delete keyManager;
}

void Player::update(double deltaT) 
{
	keyManager->update();

	if (keyManager->keyDown(K_UP)) {
		pos.x += 0.1f;
	}else if (keyManager->keyDown(K_DOWN)) {
		pos.x -= 0.1f;
	}else if (keyManager->keyDown(K_RIGHT)) {
		pos.y += 0.1f;
	}else if (keyManager->keyDown(K_LEFT)) {
		pos.y -= 0.1f;
	}

	cout << pos.x << " / " << pos.y << endl;
}

void Player::render() {

}
