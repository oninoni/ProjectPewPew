#pragma once
class BGGrid
{
private:
	vector<Tile> tileMap;
	int sizeX;
	int sizeY;
public:
	BGGrid();
    BGGrid(int sizeX, int sizeY);
    ~BGGrid();

	void update(double deltaT);
	void render();
};