#include "stdafx.h"

RectHitbox::RectHitbox(vec2 p, vec2 s) :
    Hitbox(p){
    size = s;
}


RectHitbox::~RectHitbox() {
}

HitboxType RectHitbox::getType() {
    return HitboxType::Rectangle;
}

bool RectHitbox::collidesWith(Hitbox * box) {
    if (box->getType() == HitboxType::Circle) {
        // TODO
    }
    else if (box->getType() == HitboxType::Rectangle) {
        return  position + size >= box->position && box->position + ((RectHitbox*)box)->size >= position;
    }
}

bool RectHitbox::collidesWith(Line l) {
    return  (l.direction.x == 0 && l.position.y > position.y && l.position.y < position.y + size.y) ||              // Check if vertical line
                                                                                                                    // If not vertical it has to intersect one of the sides
        (l.getYAt(position.x) > position.y && l.getYAt(position.x) <= position.y + size.y) ||                       //Left Side Check
        (l.getYAt(position.x + size.x) > position.y && l.getYAt(position.x + size.x) <= position.y + size.y);       //Right Side Check
}

bool RectHitbox::collidesWith(vec2 pos) {
    return pos > position && pos < position + size;
}
