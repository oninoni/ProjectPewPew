#include "stdafx.h"

bool BGTileData::isBackground() const
{
    return false;
}

bool FGTileData::isBackground() const
{
    return true;
}

void Tile::updateVAO()
{
    struct {
        vec2 pos;
        vec2 tex;
        vec2 minborder;
        vec2 maxborder;
    } vertexData[6];

    textureMap->setTexture(data->getTexture());

    for (auto& d : vertexData)
    {
        d.minborder = textureMap->getMinBorder();
        d.maxborder = textureMap->getMaxBorder();
    }

    vertexData[0].pos = vec2(pos.x + 0, pos.y + 0);
    vertexData[0].tex = textureMap->getTexCoord(vec2(0, 0));

    vertexData[1].pos = vec2(pos.x + 1, pos.y + 0);
    vertexData[1].tex = textureMap->getTexCoord(vec2(1, 0));

    vertexData[2].pos = vec2(pos.x + 1, pos.y + 1);
    vertexData[2].tex = textureMap->getTexCoord(vec2(1, 1));

    vertexData[3].pos = vec2(pos.x + 1, pos.y + 1);
    vertexData[3].tex = textureMap->getTexCoord(vec2(1, 1));

    vertexData[4].pos = vec2(pos.x + 0, pos.y + 1);
    vertexData[4].tex = textureMap->getTexCoord(vec2(0, 1));

    vertexData[5].pos = vec2(pos.x + 0, pos.y + 0);
    vertexData[5].tex = textureMap->getTexCoord(vec2(0, 0));

    vao->changeVerticies(6 * grid->getIndex(pos), 6, data);
}

Tile::Tile(ivec2 pos, Game * g, VAO * vao, TileData * data)
{
    this->pos = pos;
    this->textureMap = g->getTextureMap();
    this->vao = vao;
    this->data = data;
}

Tile::~Tile()
{

}

bool Tile::operator==(Tile & other)
{
    return data->getType() == other.data->getType();
}

bool Tile::operator!=(Tile & other)
{
    return !(*this == other);
}

BGTile::BGTile(ivec2 pos, Game * g, VAO * vao, BGTileData * data)
    : Tile(pos, g, vao, data)
{
    this->grid = g->getBGGrid();
}

FGTile::FGTile(ivec2 pos, Game * g, VAO * vao, FGTileData * data)
    : Tile(pos, g, vao, data)
{
    this->grid = g->getFGGrid();
}