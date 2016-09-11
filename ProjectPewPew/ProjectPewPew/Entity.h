#pragma once
class Entity abstract
{
private:
    Location location;
    vec2 speed;

    Hitbox* hitbox;

    bool isDead;

    TextureMap* textureMap;

    VAO* main;
    string texture;
public:
    Entity(Game* g, Location l, vec2 s, string t);
    ~Entity();

    virtual void buildVAO();

    virtual void update(float deltaT);
    virtual void render();

    void kill();

    Hitbox* getHitbox();
};

