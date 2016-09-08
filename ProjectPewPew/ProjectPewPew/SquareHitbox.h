#pragma once
class RectHitbox : Hitbox{
public:
    RectHitbox(vec2 p, vec2 s);
    ~RectHitbox();

    HitboxType getType();

    bool collidesWith(Hitbox* box);
    bool collidesWith(Line l);
    bool collidesWith(vec2 pos);

    vec2 size;
};