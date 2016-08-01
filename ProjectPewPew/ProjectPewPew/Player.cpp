#include "stdafx.h"

Player::Player(float x, float y)
{
    Player(vec2(x, y));
}

Player::Player(vec2 pos) 
{
    this->pos = pos;
}

Player::~Player()
{
}

void Player::update(double deltaT) 
{
    // dafür schreibste ja grad ein controls manager :P
	//int key = glfwGetKey(window, GLFW_KEY_W);
}

void Player::render() {
}
