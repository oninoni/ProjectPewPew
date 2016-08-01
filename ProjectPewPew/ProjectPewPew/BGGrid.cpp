#include "stdafx.h"

BGGrid::BGGrid() {

}

BGGrid::BGGrid(int sX, int sY)
{
	sizeX = sX;
	sizeY = sY;

	for (int x = 0; x < sizeX; x++) {
		for (int y = 0; y < sizeY; y++) {
			tileMap.push_back(Tile(x, y, "Test"));
		}
	}
}


BGGrid::~BGGrid()
{
}

void BGGrid::update(double deltaT) {

}

void BGGrid::render() {
	for (size_t i = 0; i < tileMap.size(); i++) {
		tileMap.at(i);
	}
}
