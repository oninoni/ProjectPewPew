#include "stdafx.h"

void BGGrid::buildVAO() {
	vao->generate(tileMap.size() * 6, buStaticDraw);

	vao->map(baWriteOnly);

	for (size_t i = 0; i < tileMap.size(); i++) {
		tileMap.at(i).addToVAO(vao);
	}

	vao->unmap();
}

BGGrid::BGGrid() {

}

BGGrid::BGGrid(int sX, int sY, Game* g)
{
	sizeX = sX;
	sizeY = sY;

	for (int x = 0; x < sizeX; x++) {
		for (int y = 0; y < sizeY; y++) {
			tileMap.push_back(Tile(x, y, "grass", g));
		}
	}

	vao = new VAO(g->getTextureShader());

	vao->addAttribute(2, "vpos");
	vao->addAttribute(2, "vtexcoord");
	vao->genAttributes();

	uniformLocation = g->getTextureShader()->getUniformLocation("model");

	buildVAO();
}


BGGrid::~BGGrid()
{
}

void BGGrid::update(double deltaT) {

}

void BGGrid::render() {
	matrix3 matrix42;
	matrix42.loadIdentity();
	glUniformMatrix3fv(uniformLocation, 1, blFalse, matrix42.ptr());
	vao->render();
}
