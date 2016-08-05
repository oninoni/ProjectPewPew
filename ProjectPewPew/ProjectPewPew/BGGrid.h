#pragma once
class BGGrid
{
private:
	vector<Tile> tileMap;
	ivec2 size;

	int uniformLocation;

	VAO* vao;

	void buildVAO();
public:
	BGGrid();
    BGGrid(int sizeX, int sizeY, Game* g);
    ~BGGrid();

	void update(double deltaT);
	void render();

	ivec2 getSize();
};