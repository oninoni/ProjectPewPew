#include "stdafx.h"


RayCaster::RayCaster(ivec2 s, vec2 p, vec2 d){
    size = s;
    point = p;
    direction = d;

    X.up = direction.x > 0 ? 1 : direction.x == 0 ? 0 : -1;
    Y.up = direction.y > 0 ? 1 : direction.y == 0 ? 0 : -1;

    X.pos = ivec2((int)p.x, (int)p.y);
    Y.pos = ivec2((int)p.x, (int)p.y);

    X.isHorizontal = false;
    Y.isHorizontal = true;

    calcDirection(X);
    calcDirection(Y);

    lastWasX = X.distance < Y.distance;
}

RayCaster::~RayCaster(){
}

void RayCaster::calcDirection(RayCastData& d) {
    vec2 plane = d.isHorizontal ? vec2(1,0) : vec2(0,1);
	int offset = d.up == 1 ? 1 : 0;
    ivec2 planePos = d.pos + (d.isHorizontal ? ivec2(0, offset) : ivec2(offset, 0));
    float v = (direction.x * (planePos.y - point.y) - direction.y * (planePos.x - point.x)) / (plane.x * direction.y - plane.y * direction.x);
    float u = (planePos.x + v * plane.x - point.x) / direction.x;

    d.hitPos = vec2(planePos.x, planePos.y) + plane * v;
    d.distance = (point - d.hitPos).length();
}

bool RayCaster::next()
{
    if (X.up == 0) {
        Y.pos = ivec2(Y.pos.x, Y.pos.y + Y.up);
        active = Y;
        calcDirection(Y);
    }
    else if (Y.up == 0) {
        X.pos = ivec2(X.pos.x + X.up, X.pos.y);
        active = X;
        calcDirection(X);
    }
    else {
        if (lastWasX) {
            X.pos = ivec2(X.pos.x + X.up, Y.pos.y);
            active = X;
            calcDirection(X);
        }
        else {
            Y.pos = ivec2(X.pos.x, Y.pos.y + Y.up);
            active = Y;
            calcDirection(Y);
        }
        lastWasX = X.distance < Y.distance;
    }

    if (active.pos.x < size.x && active.pos.x >= 0 && active.pos.y < size.y && active.pos.y >= 0) {
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
