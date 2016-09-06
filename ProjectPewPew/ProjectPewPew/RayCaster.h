#pragma once

struct RayCastData {
    ivec2 pos;
    vec2 hitPos;
    float distance;
    char up;
    bool isHorizontal;

    RayCastData(){
        pos = ivec2(0, 0);
        hitPos = vec2(0, 0);
        distance = 0.0f;
        up = false;
        isHorizontal = false;
    }
};

class RayCaster
{
private:
    ivec2 size;
    vec2 point;
    vec2 direction;

    RayCastData active;

    RayCastData X;
    RayCastData Y;

    bool lastWasX;

    void calcDirection(RayCastData& d);
public:
    RayCaster(ivec2 s, vec2 p, vec2 d);
    ~RayCaster();

    bool next();

    float getDistance();
    ivec2 getTilePos();
    vec2 getHitPos();
};

