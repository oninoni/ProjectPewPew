#include "stdafx.h"

void FGGrid::buildTileMap(Game* g) {
	tileMap.clear();

	string s;
	bool solid;

	for (int x = 0; x < size.x; x++) {
		for (int y = 0; y < size.y; y++) {
			switch (rand() % 5) {
			case 0:
				s = "stone_bricks";
				solid = true;
				break;
			default:
				s = "air";
				solid = false;
				break;
			}
			tileMap.push_back(Tile(ivec2(x, y), s, g, solid));
		}
	}
}

FGGrid::FGGrid(int sizeX, int sizeY, Game* g):
	BGGrid(sizeX, sizeY, g)
{
}

FGGrid::~FGGrid()
{
}

void FGGrid::init(){
	buildTileMap(game);

	vao = new VAO(game->getTextureShader());

	uniformLocation = game->getTextureShader()->getUniformLocation("model");

	buildVAO();
}

void FGGrid::update(double deltaT) {
	BGGrid::update(deltaT);
}

void FGGrid::render() {
	BGGrid::render();
}
