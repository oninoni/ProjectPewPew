#include "stdafx.h"

void BGGrid::buildVAO() {
	vao->generate(size.x * size.y * 6, buStaticDraw);

	vao->map(baWriteOnly);

	for (DWORD i = 0; i < size.x * size.y; i++) 
		tileMap[i].addToVAO(vao);	      

	vao->unmap();
}

void BGGrid::buildTileMap(Game* g, string block) {
	tileMap.clear(); 	
	for (int x = 0; x < size.x; x++) 
		for (int y = 0; y < size.y; y++)                                    
            tileMap.push_back(Tile(ivec2(x, y), block, g));
}

BGGrid::BGGrid(int sX, int sY, Game* g)
{
	size.x = sX;
	size.y = sY;

	game = g;

    buildTileMap(game);

    vao = new VAO(game->getTextureShader());

    uniformLocation = game->getTextureShader()->getUniformLocation("model");

    buildVAO();
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

Tile & BGGrid::getTileAt(vec2 p) {
	return getTileAt(ivec2((int) p.x, (int) p.y));
}

Tile & BGGrid::getTileAt(ivec2 p) {
    return tileMap[p.y + p.x * size.y];
}

void BGGrid::setTileAt(ivec2 p, Tile t)
{
    tileMap[p.y + p.x * size.y] = t;
    buildVAO();
}

void BGGrid::fill(TileData tile)
{
    for (Tile &t : tileMap)
        t.assign(tile);
}
