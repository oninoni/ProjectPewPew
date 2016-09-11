#include "stdafx.h"

Entity::Entity(Game* g, Location l, vec2 s, string t) {
    location = l;

    location.setOffset(vec2(-0.5f, -0.5f));

    speed = s;
    texture = t;

    main = new VAO(g->getTextureShader());

    textureMap = g->getTextureMap();

    buildVAO();
}

Entity::~Entity() {
    delete main;
}

void Entity::buildVAO() {
    textureMap->setTexture(texture);
    
    struct {
        vec2 pos;
        texcoord tex;
        texcoord minborder;
        texcoord maxborder;
    } data;

    data.minborder = textureMap->getMinBorder();
    data.maxborder = textureMap->getMaxBorder();

    main->generate(6, buDynamicDraw);

    main->map(baWriteOnly);
    data.pos = vec2(0, 0);
    data.tex = textureMap->getTexCoord(vec2(0, 0));
    main->addVertex(&data);
    data.pos = vec2(1, 0);
    data.tex = textureMap->getTexCoord(vec2(1, 0));
    main->addVertex(&data);
    data.pos = vec2(1, 1);
    data.tex = textureMap->getTexCoord(vec2(1, 1));
    main->addVertex(&data);
    data.pos = vec2(1, 1);
    data.tex = textureMap->getTexCoord(vec2(1, 1));
    main->addVertex(&data);
    data.pos = vec2(0, 1);
    data.tex = textureMap->getTexCoord(vec2(0, 1));
    main->addVertex(&data);
    data.pos = vec2(0, 0);
    data.tex = textureMap->getTexCoord(vec2(0, 0));
    main->addVertex(&data);
    main->unmap();
}

void Entity::update(float deltaT) {
    location.rotate(deltaT * 90);
    location.translatePosition(speed * deltaT);
}

void Entity::render() {
    main->getPos() = location;
    main->render();
}

void Entity::kill() {
    isDead = true;
}

Hitbox * Entity::getHitbox() {
    return hitbox;
}
