#pragma once

class TextureMap :
    public Texture
{
private:
    int size;
    int maxTextureCount;

    vector<TextureData> tiles;

public:
    TextureMap(int maxTextureCount);
    ~TextureMap();
};

