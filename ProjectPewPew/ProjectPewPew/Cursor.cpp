#include "stdafx.h"



Cursor::Cursor(Game* g) {
	window = g->getWindow();
	player = g->getPlayer();

	vaoLaser = new VAO(g->getLaserShader());

	vaoLaser->addAttribute(2, "vpos");
	vaoLaser->addAttribute(2, "vtexcoord");
	vaoLaser->addAttribute(4, "vcolor");
	vaoLaser->genAttributes();

	vaoLaser->generate(6, buStaticDraw);


	vaoTarget = new VAO(g->getTextureShader());
}


Cursor::~Cursor() {

}

void Cursor::render() {
	double x, y;
	glfwGetCursorPos(window, &x, &y);
	xPos = x;
	yPos = y;

	cout << xPos << "Lol" << yPos << endl;

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
