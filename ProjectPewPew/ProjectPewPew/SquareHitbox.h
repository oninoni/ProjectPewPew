#pragma once
class SquareHitbox : Hitbox{
public:
    SquareHitbox(vec2 p, vec2 s);
    ~SquareHitbox();

    HitboxType getType();

    //bool collidesWith(Hitbox* box);
    //bool collidesWith(vec2 pos, vec2 dir);
    bool collidesWith(vec2 pos);

    vec2 size;
};