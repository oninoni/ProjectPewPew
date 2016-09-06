#pragma once
class BGGrid
{
private:

	void buildTileMap(Game* g);
protected:
	int uniformLocation;
	void buildVAO();

	Game* game;
	ivec2 size;
	vector<Tile> tileMap;

	VAO* vao;
public:
	BGGrid();
    BGGrid(int sizeX, int sizeY, Game* g);
    ~BGGrid();

	void init();

	void update(double deltaT);
	void render();

	ivec2 getSize();

	vector<Tile> getTileMap();
	Tile& getTileAt(vec2 p);
	Tile& getTileAt(ivec2 p);

    void setTileAt(ivec2 p, Tile t);
};