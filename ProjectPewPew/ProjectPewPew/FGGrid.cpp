#include "stdafx.h"

FGGrid::FGGrid()
{
	BGGrid::BGGrid();
}                  

FGGrid::~FGGrid()
{
	BGGrid::~BGGrid();
}

void FGGrid::update(double deltaT) {
	BGGrid::update(deltaT);
}

void FGGrid::render() {
	BGGrid::render();
}
