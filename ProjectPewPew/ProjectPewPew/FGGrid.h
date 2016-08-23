#pragma once
class FGGrid : public BGGrid
{
private:
	void buildTileMap(Game* g);
public:
    FGGrid(int sizeX, int sizeY, Game* g);
    ~FGGrid();

	void init();

	void update(double deltaT);
	void render();
};

