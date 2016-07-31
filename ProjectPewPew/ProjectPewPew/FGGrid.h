#pragma once
class FGGrid : public BGGrid
{
public:
    FGGrid(int sizeX, int sizeY);
    ~FGGrid();

	void update(double deltaT);
	void render();
};

