#include "stdafx.h"

Properties::Properties()
    : properties(TP_SIZE)
{
}

bool Properties::is(TileProperty prop)
{
    return properties[prop];
}

void Properties::set(TileProperty prop)
{
    properties[prop] = true;
}

void Properties::clear(TileProperty prop)
{
    properties[prop] = false;
}

void Properties::clearAll(TileProperty prop)
{
    properties.clear();
}

TileData::TileData(string texture)
{
    this->texture = texture;      
}

Tile::Tile(ivec2 pos, string texture, Game * g)
    : TileData(texture)
{
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

string TileData::getTexture()
{
    return texture;
}

void TileData::assign(TileData &other)
{
    texture = other.texture;
}
