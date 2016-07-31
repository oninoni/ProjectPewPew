#include "stdafx.h"

FGGrid::FGGrid(int sizeX, int sizeY)
{
	BGGrid::BGGrid(sizeX, sizeY);
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
