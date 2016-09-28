#pragma once
class BGGrid
{
private:        
    void buildTileMap(Game * g, string block = "air");

protected:
	int uniformLocation;

	Game* game;
	ivec2 size;
	vector<Tile> tileMap;

	VAO* vao;


public:
    BGGrid(int sizeX, int sizeY, Game* g);
    ~BGGrid();

	void update(float deltaT);
	void render();

	ivec2 getSize();

	vector<Tile> getTileMap();
	Tile& operator[](ivec2 p);
    
    int getIndex(ivec2 p);

    void fill(TileData tile);
};