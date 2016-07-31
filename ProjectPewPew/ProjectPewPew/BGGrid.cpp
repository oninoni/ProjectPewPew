#include "stdafx.h"

BGGrid::BGGrid() {

}

BGGrid::BGGrid(int sX, int sY)
{
	sizeX = sX;
	sizeY = sY;

	for (int x = 0; x < sizeX; x++) {
		for (int y = 0; y < sizeY; y++) {
			Tile* tile = new Tile(x, y, "Test");
			tileMap.push_back(*tile);
		}
	}
}


BGGrid::~BGGrid()
{

}

void BGGrid::update(double deltaT) {

}

void BGGrid::render() {
	for (int i = 0; i < tileMap.size(); i++) {
		tileMap.at(i);
	}
}
