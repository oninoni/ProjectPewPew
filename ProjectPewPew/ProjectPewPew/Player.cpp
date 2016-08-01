#include "stdafx.h"

Player::Player(float x, float y, GLFWwindow* w):
	Player(vec2(x, y), w)
{

}

Player::Player(vec2 pos, GLFWwindow* w)
{
	window = w;
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

	if (keyManager->keyPressed(K_UP)) {
		cout << "GEDRÖCKT!!!" << endl;
	}
}

void Player::render() {
}
