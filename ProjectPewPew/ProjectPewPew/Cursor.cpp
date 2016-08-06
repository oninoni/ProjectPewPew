#include "stdafx.h"



Cursor::Cursor(Game* g) {
	window = g->getWindow();
	player = g->getPlayer();

	vaoLaser = new VAO(g->getLaserShader()); 
	vaoLaser->generate(6, buDynamicDraw);    

	vaoTarget = new VAO(g->getTextureShader());
    vaoTarget->generate(6, buStaticDraw);
}


Cursor::~Cursor() {
    
}

void Cursor::render() {

    // Possseidon: Put this stuff in InputManager
    //             InputManager shall then only return the y = [-1,+1] and x = [-aspect,+aspect]
    //             And I will give InputManager a second function that uses yours and converts to mapcoords 
    double x, y;
	glfwGetCursorPos(window, &x, &y);
	xPos = (float)x;
	yPos = (float)y;

    //cout << xPos << "/" << yPos << endl;

	/*vec2 points[4];

	points[0] = player->getPos();

	struct {
		vec2 pos;
		vec2 tex;
		float r, g, b, a;
	} data;

	vaoLaser->map(baWriteOnly);
	vaoLaser->
	vaoLaser->unmap();

	vaoLaser->render();
	vaoTarget->render();*/
}
