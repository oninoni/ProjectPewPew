#pragma once

enum HitboxType {
    Rect,
    Circle
};

class Hitbox {
public:
    Hitbox(vec2 p);
    ~Hitbox();

    virtual HitboxType getType() = 0;

    virtual bool collidesWith(Hitbox* box) = 0;
    virtual bool collidesWith(Line l, vec2 &collision = vec2()) = 0;
    virtual bool collidesWith(vec2 pos, vec2 &collision = vec2()) = 0;

    vec2 position;
};