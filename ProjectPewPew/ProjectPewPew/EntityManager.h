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

    vector<Entity*> rayCastAll(Line l, float length, vector<vec2> &hitPos = vector<vec2>());
};