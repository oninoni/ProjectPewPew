#include "stdafx.h"

void BGGrid::buildTileMap(Game* g, string block) {
	tileMap.clear(); 	
	for (int x = 0; x < size.x; x++) 
		for (int y = 0; y < size.y; y++)                                    
            tileMap.push_back(Tile(ivec2(x, y), block, g, this, vao));
}

int BGGrid::getIndex(ivec2 p)
{
    return p.x + size.x * p.y;
}

BGGrid::BGGrid(int sX, int sY, Game* g)
{
	size.x = sX;
	size.y = sY;

	game = g;

    buildTileMap(game);

    vao = new VAO(game->getTextureShader());

    uniformLocation = game->getTextureShader()->getUniformLocation("model");

    vao->generate(6 * size.x * size.y, buDynamicDraw);
}


BGGrid::~BGGrid()
{
    delete vao;
}

void BGGrid::update(float deltaT) {

}

void BGGrid::render() {
	Matrix3 matrix;
	matrix.loadIdentity();
	glUniformMatrix3fv(uniformLocation, 1, blFalse, matrix.ptr());
	vao->render();
}

ivec2 BGGrid::getSize() {
	return size;
}

vector<Tile> BGGrid::getTileMap() {
	return tileMap;
}

Tile & BGGrid::operator[](ivec2 p) {
    return tileMap[p.y + p.x * size.y];
}

void BGGrid::fill(TileData tile)
{
    for (Tile &t : tileMap)
        t = tile;
}
