#pragma once
class FGGrid : public BGGrid
{
public:
    FGGrid(int sizeX, int sizeY, Game* g);
    ~FGGrid();

	void update(double deltaT);
	void render();
};

