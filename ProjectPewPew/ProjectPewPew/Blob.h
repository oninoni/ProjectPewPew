#pragma once
class Blob : public Entity{
public:
    Blob(Game* g, Location l, vec2 s);
    ~Blob();

    void buildVAO();

    void update(float deltaT);
    void render();
};

