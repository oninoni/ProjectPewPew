#include "stdafx.h"

Entity::Entity(Game* g) {
    main = new VAO(g->getTextureShader());
    //buildVAO();
}

Entity::~Entity() {
    delete main;
}

void Entity::update(float deltaT) {
}

void Entity::render() {
    main->render();
}

void Entity::kill() {
    isDead = true;
}
