#pragma once

class RoundHitbox : Hitbox{
public:
    RoundHitbox(vec2 p, float r);
    ~RoundHitbox();

    HitboxType getType();

    bool collidesWith(Hitbox* box);
    bool collidesWith(Line l, vec2 &collision = vec2());
    bool collidesWith(vec2 pos, vec2 &collision = vec2());

    float radius;
};

