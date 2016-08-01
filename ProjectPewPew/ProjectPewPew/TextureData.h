#pragma once
class TextureData
{
private:
    cvec2 size;
    byte* data;
    string name;

public:
    TextureData(string filename);
    TextureData(cvec2 size, string name);
    TextureData(TextureData &other);
    ~TextureData();

    void freeData();

    cvec2 getSize();
    string getName();
    byte* getData();
};

