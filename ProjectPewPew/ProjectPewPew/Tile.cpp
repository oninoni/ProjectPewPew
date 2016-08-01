#include "stdafx.h"

Tile::Tile(int x, int y, string texture) 
{
    Tile(ivec2(x, y), texture);
}

Tile::Tile(ivec2 pos, string texture)
{
    this->pos = pos;
    this->texture = texture;
}

Tile::~Tile() 
{

}

void Tile::addToVAO(VAO vao) 
{

}
