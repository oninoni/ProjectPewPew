#include "stdafx.h"

RectHitbox::RectHitbox(vec2 p, vec2 s):
    Hitbox(p){
    size = s;
}

RectHitbox::~RectHitbox() {
}

HitboxType RectHitbox::getType() {
    return HitboxType::Rect;
}

bool RectHitbox::collidesWith(Hitbox * box) {
    if (box->getType() == HitboxType::Circle) {
        RoundHitbox* rbox = (RoundHitbox*)box;
        //TODO
    }
    else if (box->getType() == HitboxType::Rect) {
        return  position + size >= box->position &&
            box->position + ((RectHitbox*)box)->size >= position;
    }
}

bool RectHitbox::collidesWith(Line l, vec2 &collision) {
    if (l.direction.x == 0 || l.direction.y == 0) {
        // TODO Special Stuff
    }
    else {
        Line horizontCheck(position + vec2(0, l.direction.y > 0 ? 1.0f : -1.0f), vec2(1, 0));
        Line verticalCheck(position + vec2(l.direction.x > 0 ? 1 : -1.0f, 0.0f), vec2(0, 1));

        IntersectionData dh, dv;

        l.intersect(horizontCheck, dh);
        l.intersect(verticalCheck, dv);

        vec2 ph = l[dh.u];
        vec2 pv = l[dv.u];

        bool hInter = (ph >= position && ph <= position + size);
        bool vInter = (pv >= position && pv <= position + size);

        if (hInter && vInter) {
            if (dh.u > dv.u) {
                collision = pv;
                return true;
            }
            else {
                collision = ph;
                return true;
            }
        }
        else if (hInter) {
            collision = ph;
            return true;
        }
        else if (vInter) {
            collision = pv;
            return true;
        }
        else {
            return false;
        }
    }
}

bool RectHitbox::collidesWith(vec2 pos, vec2 &collision) {
    collision = pos;
    return pos > position && pos < position + size;
}
