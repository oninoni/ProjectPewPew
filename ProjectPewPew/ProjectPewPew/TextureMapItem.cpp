#include "stdafx.h"

TextureMapItem::TextureMapItem(string filename) :
    TextureData::TextureData(filename)
{
}

TextureMapItem::TextureMapItem(cvec2 size, string name) :
    TextureData::TextureData(size, name)
{
}

TextureMapItem::TextureMapItem(TextureMapItem & textureMapItem) :
    TextureData::TextureData(textureMapItem)
{
    pos = textureMapItem.pos;
}