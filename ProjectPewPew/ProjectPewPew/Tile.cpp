#include "stdafx.h"

Tile::Tile(int x, int y, string texture, Game* g) :
	Tile(ivec2(x, y), texture, g)
{
}

Tile::Tile(ivec2 pos, string texture, Game* g)
{
    this->pos = pos;
    this->texture = texture;
	textureMap = g->getTextureMap();
}

Tile::~Tile() 
{

}

void Tile::addToVAO(VAO* vao) 
{
	struct {
		vec2 pos;
		vec2 tex;
	} data;

	data.pos = vec2(pos.x + 0, pos.y + 0);
	data.tex = textureMap->getTexCoord(texture, vec2(0, 0));
	vao->addVertex(&data);
	data.pos = vec2(pos.x + 1, pos.y + 0);
	data.tex = textureMap->getTexCoord(texture, vec2(1, 0));
	vao->addVertex(&data);
	data.pos = vec2(pos.x + 1, pos.y + 1);
	data.tex = textureMap->getTexCoord(texture, vec2(1, 1));
	vao->addVertex(&data);
	data.pos = vec2(pos.x + 1, pos.y + 1);
	data.tex = textureMap->getTexCoord(texture, vec2(1, 1));
	vao->addVertex(&data);
	data.pos = vec2(pos.x + 0, pos.y + 1);
	data.tex = textureMap->getTexCoord(texture, vec2(0, 1));
	vao->addVertex(&data);
	data.pos = vec2(pos.x + 0, pos.y + 0);
	data.tex = textureMap->getTexCoord(texture, vec2(0, 0));
	vao->addVertex(&data);
}
