#pragma once
class EntityManager {
    vector<Entity*> entities;

    Game* game;
public:
    EntityManager(Game* g);
    ~EntityManager();

    void update(float deltaT);
    void render();

    void addEntity(Entity* e);
};

