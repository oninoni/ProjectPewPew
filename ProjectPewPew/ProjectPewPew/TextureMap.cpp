#include "stdafx.h"

TextureMap::TextureMap()
{     
    textureCount = 0;
    texSize = cvec2(0, 0);
}

TextureMap::~TextureMap()
{
    for (pair<string, TextureMapItem*> item : tiles)
        delete item.second;
}

bool TextureMap::addTexture(string filename)
{
    TextureMapItem* item = new TextureMapItem(filename);

    if (tiles[item->getName()])
    {
        cout << "Tried to create multiple textures with name " << filename << endl;
        return false;
    }
    if (texSize == cvec2(0, 0))
    {
        texSize = item->getSize();
    }      
    else if (texSize != item->getSize())
    {
        cout << "All textures must have the same size" << endl;
        cout << filename << " is " << item->getSize().x << "x" << item->getSize().y << " pixels" << endl;
        cout << "Should be " << texSize.x << "x" << texSize.y << " pixels" << endl;
        return false;
    }

    tiles[item->getName()] = item;
    textureCount++;
    return true;
}

bool TextureMap::delTexture(string name)
{
    if (tiles[name])
    {
        tiles[name]->freeData();
        tiles.erase(name);
        textureCount--;
        return true;
    }
    return false;
}

// if you want to rebuild the page but keep the old textures available, don't free them
void TextureMap::buildPage(bool freeTextureData)
{
    bind();

    size = 1;
    while (size * size < textureCount)
        size *= 2;

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, size * texSize.x, size * texSize.y, 0, GL_BGRA, GL_UNSIGNED_BYTE, NULL);

    int x = 0;
    int y = 0;
    for (pair<string, TextureMapItem*> pair : tiles)
    {
        TextureMapItem* t = pair.second;
        t->pos = vec2((float)x, (float)y) / (float)size;

        glTexSubImage2D(GL_TEXTURE_2D, 0, x, y, texSize.x, texSize.y, GL_BGRA, GL_UNSIGNED_BYTE, t->getData());

        if ((x = (x += texSize.x) % size) == 0)
            y += texSize.y;

        if (freeTextureData)
            t->freeData();
    }
}

texcoord TextureMap::getTexCoord(string name, texcoord texCoord)
{
    texcoord result;
    result.x = tiles[name]->pos.x + texCoord.x * texSize.x / (size * texSize.x);
    result.y = tiles[name]->pos.y + texCoord.y * texSize.y / (size * texSize.y);
    return result;
}