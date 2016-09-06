#pragma once

struct RayCastData {
    ivec2 pos;
    vec2 hitPos;
    float distance;
    bool up;
    bool isX;

    RayCastData(){
        pos = ivec2(0, 0);
        hitPos = vec2(0, 0);
        distance = 0.0f;
        up = false;
        isX = false;
    }

    RayCastData(RayCastData &other){
        distance = other.distance;
        hitPos.x = other.hitPos.x;
        hitPos.y = other.hitPos.y;
        pos.x = other.pos.x;
        pos.y = other.pos.y;
        up = other.up;
        isX = other.isX;
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

