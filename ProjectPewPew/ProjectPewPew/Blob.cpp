#include "stdafx.h"

Blob::Blob(Game* g, Location l, vec2 s):
    Entity(g, l, s, "blob"){
    hitbox = new RectHitbox(l.getPosition(), vec2(1.0f, 1.0f));
    l.setScale(0.5);
}

Blob::~Blob(){
}

void Blob::buildVAO() {
    Entity::buildVAO();
}

void Blob::update(float deltaT) {
    Entity::update(deltaT);
}

void Blob::render() {
    Entity::render();
}
