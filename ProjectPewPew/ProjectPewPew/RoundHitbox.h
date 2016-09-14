#pragma once

class RoundHitbox : public Hitbox{
public:
    RoundHitbox(vec2 p, float r);
    ~RoundHitbox();

    HitboxType getType();

    bool collidesWith(Hitbox* box);
    bool collidesWith(Line l, float length = 0.0f);
    bool collidesWith(vec2 pos, vec2 &collision = vec2());

    float radius;
};

