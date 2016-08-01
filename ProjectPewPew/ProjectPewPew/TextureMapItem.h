#pragma once

class TextureMapItem : public TextureData
{
public: 
    TextureMapItem(string filename);
    TextureMapItem(cvec2 size, string name);
    TextureMapItem(TextureMapItem &textureMapItem);

    texcoord pos;  
};

