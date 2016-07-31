#include "stdafx.h"

Player::Player(GLFWwindow* w, float x, float y){
	window = w;
	xPos = x;
	yPos = y;
}


Player::~Player(){
}

void Player::update(double deltaT) {
	int key = glfwGetKey(window, GLFW_KEY_W);
}

void Player::render() {
}
