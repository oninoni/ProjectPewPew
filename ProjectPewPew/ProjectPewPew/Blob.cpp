#include "stdafx.h"

Blob::Blob(Game* g, Location l, vec2 s):
    Entity(g, l, s, "blob"){

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
