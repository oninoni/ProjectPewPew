#pragma once
class Texture
{
private:
    unsigned int ID;
    int unitID;

public:
    Texture();
    ~Texture();

    void bind();

    void uniform(Shader &shader, string name);

    static void init();

    static bool initialized;
    static int maxUnits;
    static int unitCount;
    static Texture* boundTexture;
};

