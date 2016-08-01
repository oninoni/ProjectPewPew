#include "stdafx.h"

TextureMap::TextureMap(int maxTextureCount)
{
    size = (int)ceil(log2(maxTextureCount));
    this->maxTextureCount = size * size;
}

TextureMap::~TextureMap()
{
}