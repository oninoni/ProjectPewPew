#include "stdafx.h"

EntityManager::EntityManager(Game* g) {
    game = g;
}

EntityManager::~EntityManager() {

}

void EntityManager::update(float deltaT) {
    for (Entity* e : entities) {
        e->update(deltaT);
    }
}

void EntityManager::render() {
    for (Entity* e : entities) {
        e->render();
    }
}

void EntityManager::addEntity(Entity * e) {
    entities.push_back(e);
}

vector<Entity*> EntityManager::rayCastAll(Line l, float length, vector<vec2> &hitPos) {
    vector<Entity*> collided;
    vector<float> distance;
    for (Entity* e : entities) {
        vec2 collision;
        if (e->getHitbox()->collidesWith(l, collision)) {
            float dis = l.position.distanceTo(collision);
            if (dis <= length) {
                int n = 0;
                for (float d : distance) {
                    if (d >= dis) {
                        break;
                    }
                    n++;
                }
                collided.insert(collided.begin() + n, e);
                hitPos.insert(hitPos.begin() + n, collision);
            }
        }
    }
    return collided;
}
