#include "stdafx.h"

FGGrid::FGGrid(int sizeX, int sizeY, Game* g):
	BGGrid(sizeX, sizeY, g)
{
}

FGGrid::~FGGrid()
{
}

void FGGrid::update(double deltaT) {
	BGGrid::update(deltaT);
}

void FGGrid::render() {
	BGGrid::render();
}
