#include "stdafx.h"

RoundHitbox::RoundHitbox(vec2 p, float r):
    Hitbox(p){
    radius = r;
}

RoundHitbox::~RoundHitbox() {
}

HitboxType RoundHitbox::getType() {
    return HitboxType::Circle;
}

bool RoundHitbox::collidesWith(Hitbox * box) {
    HitboxType type = box->getType();
    if (type == HitboxType::Circle) {
        return box->position.distanceTo(position) <= ((RoundHitbox*)box)->radius + radius;
    }
    else if (type == HitboxType::Rectangle) {
        return ((RectHitbox*)box)->collidesWith(this);
    }
}

bool RoundHitbox::collidesWith(Line l) {
    IntersectionData data;
    l.intersect(Line(position, l.direction.cross()), data);
    return position.distanceTo(l[data.u]) <= radius;
}

bool RoundHitbox::collidesWith(vec2 pos) {
    return position.distanceTo(pos) <= radius;
}
