#include "stdafx.h"

Tile::Tile(ivec2 pos, string texture, Game* g)
{
	solid = false;
    this->pos = pos;
    this->texture = texture;
	textureMap = g->getTextureMap();
}

Tile::Tile(ivec2 pos, string texture, Game * g, bool s):
	Tile(pos, texture, g)
{
	solid = s;
}

Tile::~Tile() 
{

}

void Tile::addToVAO(VAO* vao) 
{
	struct {
		vec2 pos;
		vec2 tex;
        vec2 minborder;
        vec2 maxborder;
	} data;

    textureMap->setTexture(texture);

    data.minborder = textureMap->getMinBorder();
    data.maxborder = textureMap->getMaxBorder();

	data.pos = vec2(pos.x + 0.0f, pos.y + 0.0f);
	data.tex = textureMap->getTexCoord(vec2(0, 0));
	vao->addVertex(&data);
	data.pos = vec2(pos.x + 1.0f, pos.y + 0.0f);
	data.tex = textureMap->getTexCoord(vec2(1, 0));
	vao->addVertex(&data);
	data.pos = vec2(pos.x + 1.0f, pos.y + 1.0f);
	data.tex = textureMap->getTexCoord(vec2(1, 1));
	vao->addVertex(&data);
	data.pos = vec2(pos.x + 1.0f, pos.y + 1.0f);
	data.tex = textureMap->getTexCoord(vec2(1, 1));
	vao->addVertex(&data);
	data.pos = vec2(pos.x + 0.0f, pos.y + 1.0f);
	data.tex = textureMap->getTexCoord(vec2(0, 1));
	vao->addVertex(&data);
	data.pos = vec2(pos.x + 0.0f, pos.y + 0.0f);
	data.tex = textureMap->getTexCoord(vec2(0, 0));
	vao->addVertex(&data);
}

string Tile::getTexture() {
	return texture;
}

bool Tile::isSolid() {
	return solid;
}
