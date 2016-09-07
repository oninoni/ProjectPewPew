#pragma once
class FGGrid : public BGGrid
{
public:
    FGGrid(int sizeX, int sizeY, Game* g);
    ~FGGrid();

	void update(float deltaT);
	void render();

    bool destroyTileAt(vec2 p);
    bool destroyTileAt(ivec2 p);
};

