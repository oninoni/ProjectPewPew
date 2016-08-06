#pragma once

class TextureMap :
    public Texture
{
private:
    int size;
    int textureCount;
    cvec2 texSize;

    string_hashmap<TextureMapItem*> tiles;

    string texture;

public:
    TextureMap();
    ~TextureMap();

    bool addTexture(string filename);
    bool delTexture(string name);
    
    void buildPage(bool freeTextureData = true);

    bool setTexture(string name);

    texcoord getTexCoord(texcoord texCoord);
    texcoord getMinBorder();
    texcoord getMaxBorder();
};

