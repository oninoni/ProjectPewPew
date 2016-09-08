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
