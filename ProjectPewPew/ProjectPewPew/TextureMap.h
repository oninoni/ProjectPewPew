#pragma once

class TextureMap :
    public Texture
{
private:
    int size;
    int textureCount;
    cvec2 texSize;

    string_hashmap<TextureMapItem*> tiles;

public:
    TextureMap();
    ~TextureMap();

    bool addTexture(string filename);
    bool delTexture(string name);
    
    void buildPage(bool freeTextureData = true);

    texcoord getTexCoord(string name, texcoord texCoord);
};

