#include "stdafx.h"


RayCaster::RayCaster(ivec2 s, vec2 p, vec2 d){
    size = s;
    point = p;
    direction = d;

    X.up = direction.x > 0 ? true : false;
    Y.up = direction.y > 0 ? true : false;

    X.pos = ivec2((int)p.x + (X.up ? 1 : -1), (int)p.y);
    Y.pos = ivec2((int)p.x, (int)p.y + (Y.up ? 1 : -1));

    X.isX = true;
    Y.isX = false;

    calcDirection(X);
    calcDirection(Y);

    lastWasX = X.distance < Y.distance;
}

RayCaster::~RayCaster(){
}

void RayCaster::calcDirection(RayCastData& d) {
    vec2 plane = d.isX ? vec2(0,1) : vec2(1,0);
    float u = 
    float v = 

    plane.

    if (u > 0) {
        d.hitPos = point + direction * u;
        d.distance = (point - d.hitPos).length();
    }
    else {
        d.hitPos = vec2(0, 0);
        d.distance = (int) size.x * size.y;
    }
}

bool RayCaster::next()
{
    if (lastWasX) {
        active = X;
        X.pos = X.pos + ivec2((X.up ? 1 : -1), 0);
        calcDirection(X);
    }
    else {
        active = Y;
        Y.pos = Y.pos + ivec2(0, (Y.up ? 1 : -1));
        calcDirection(Y);
    }
    if (X.pos.x < size.x && X.pos.x > 0 && Y.pos.y < size.y && Y.pos.y > 0) {
        return true;
    }
    return false;
}

float RayCaster::getDistance(){
    return active.distance;
}

ivec2 RayCaster::getTilePos(){
    return active.pos;
}

vec2 RayCaster::getHitPos(){
    return active.hitPos;
}
