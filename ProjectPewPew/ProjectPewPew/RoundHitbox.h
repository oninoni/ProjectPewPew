#pragma once
class RoundHitbox : Hitbox{
public:
    RoundHitbox(vec2 p, float r);
    ~RoundHitbox();

    HitboxType getType();

    bool collidesWith(Hitbox* box);
    bool collidesWith(Line l);
    bool collidesWith(vec2 pos);

    float radius;
};

