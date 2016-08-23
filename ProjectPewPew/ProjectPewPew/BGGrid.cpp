#include "stdafx.h"

void BGGrid::buildVAO() {
	int size = 0;

	for (size_t i = 0; i < tileMap.size(); i++) {
		if (tileMap.at(i).getTexture() != "air") {
			size++;
		}
	}
	vao->generate(size * 6, buStaticDraw);

	vao->map(baWriteOnly);

	for (size_t i = 0; i < tileMap.size(); i++) {
		if (tileMap.at(i).getTexture() != "air") {
			tileMap.at(i).addToVAO(vao);
		}
	}

	vao->unmap();
}

void BGGrid::buildTileMap(Game* g) {
	tileMap.clear();
	
	string s;

	for (int x = 0; x < size.x; x++) {
		for (int y = 0; y < size.y; y++) {
			s = "grass";
			tileMap.push_back(Tile(ivec2(x, y), s, g));
		}
	}
}

BGGrid::BGGrid() {

}

BGGrid::BGGrid(int sX, int sY, Game* g)
{
	size.x = sX;
	size.y = sY;

	game = g;
}


BGGrid::~BGGrid()
{
    delete vao;
}

void BGGrid::init() {
	buildTileMap(game);

	vao = new VAO(game->getTextureShader());

	uniformLocation = game->getTextureShader()->getUniformLocation("model");

	buildVAO();
}

void BGGrid::update(double deltaT) {

}

void BGGrid::render() {
	Matrix3 matrix42;
	matrix42.loadIdentity();
	glUniformMatrix3fv(uniformLocation, 1, blFalse, matrix42.ptr());
	vao->render();
}

ivec2 BGGrid::getSize() {
	return size;
}

vector<Tile> BGGrid::getTileMap() {
	return tileMap;
}
