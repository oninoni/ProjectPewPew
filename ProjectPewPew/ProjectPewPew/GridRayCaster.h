#pragma once

struct GridRayCastData {
    ivec2 pos;
    vec2 hitPos;
    float distance;
    char up;
    bool isHorizontal;

    GridRayCastData(){
        pos = ivec2(0, 0);
        hitPos = vec2(0, 0);
        distance = 0.0f;
        up = false;
        isHorizontal = false;
    }
};

class GridRayCaster
{
private:
    ivec2 size;
    Line line;

    GridRayCastData active;

    GridRayCastData X;
    GridRayCastData Y;

    bool lastWasX;

    void calcDirection(GridRayCastData& d);
public:
    GridRayCaster(ivec2 s, Line l);
    ~GridRayCaster();

    bool next();

    float getDistance();
    ivec2 getTilePos();
    vec2 getHitPos();
};

