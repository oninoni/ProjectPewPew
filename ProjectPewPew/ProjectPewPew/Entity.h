#pragma once
class Entity abstract
{
private:
    Location pos;
    vec2 speed;

    bool isDead;

    VAO* main;
public:
    Entity(Game* g);
    ~Entity();

    //virtual void buildVAO() = 0;

    virtual void update(float deltaT);
    void render();

    void kill();
};

