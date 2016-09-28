#include "stdafx.h"

/*
void FGGrid::buildTileMap(Game* g) {
	tileMap.clear();

	for (int x = 0; x < size.x; x++) {
		for (int y = 0; y < size.y; y++) {
            string s = "air";
            bool solid = false;
            bool transparent = true;
            bool destructable = false;
			switch (rand() % 10) {
			case 1:	
				if (x != 15 || y != 15)
				{
					s = "stone_bricks";
					solid = true;
                    transparent = false;
                    destructable = true;
					break;
				}
            case 2:
                if (x != 15 || y != 15)
                {
                    s = "wooden_planks";
                    solid = true;
                    destructable = true;
                    break;
                }
            case 3:
            case 4:
                if (x != 15 || y != 15)
                {
                    s = "stone_sexy";
                    solid = true;
                    transparent = false;
                    break;
                }
			}
			tileMap.push_back(Tile(ivec2(x, y), s, g, solid, transparent, destructable));
		}
	}
}
*/

FGGrid::FGGrid(int sizeX, int sizeY, Game* g):
	BGGrid(sizeX, sizeY, g)
{
}

FGGrid::~FGGrid()
{
}

void FGGrid::update(float deltaT) {
	BGGrid::update(deltaT);
}

void FGGrid::render() {
	BGGrid::render();
}

bool FGGrid::destroyTileAt(vec2 p)
{
    return destroyTileAt((ivec2((int)p.x, (int)p.y)));
}

bool FGGrid::destroyTileAt(ivec2 p)
{
    Tile t = getTileAt(p);
    if (t.properties.is(tpDestructible)) {
        setTileAt(p, TileData("air"));
    }
    return false;
}