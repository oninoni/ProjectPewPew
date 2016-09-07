#include "stdafx.h"


RayCaster::RayCaster(ivec2 s, Line l){
    size = s;
    line = l;

    X.up = l.direction.x > 0 ? 1 : l.direction.x == 0 ? 0 : -1;
    Y.up = l.direction.y > 0 ? 1 : l.direction.y == 0 ? 0 : -1;

    X.pos = l.position;
    Y.pos = l.position;

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
    vec2 planePos = d.pos + (d.isHorizontal ? ivec2(0, offset) : ivec2(offset, 0));
    Line target(planePos, plane);
    IntersectionData data;
    line.intersect(target, data);

    d.hitPos = line[data.u];
    d.distance = (line.position - d.hitPos).length();
}

bool RayCaster::next()
{
    if (X.up == 0) {
        Y.pos = Y.pos + ivec2(0, Y.up);
        active = Y;
        calcDirection(Y);
    }
    else if (Y.up == 0) {
        X.pos = X.pos + ivec2(X.up, 0);
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

    if (active.pos < size && active.pos >= vec2()){
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
