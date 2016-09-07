#pragma once

enum HitboxType {
    Square,
    Circle
};

class Hitbox {
public:
    Hitbox(vec2 p);
    ~Hitbox();

    virtual HitboxType getType() = 0;

    virtual bool collidesWith(Hitbox* box) = 0;
    virtual bool collidesWith(vec2 pos, vec2 dir) = 0;
    virtual bool collidesWith(vec2 pos) = 0;

    vec2 position;
};