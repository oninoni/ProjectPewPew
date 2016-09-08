#include "stdafx.h"



Line::Line() {
    position = vec2();
    direction = vec2();
}

Line::Line(vec2 p, vec2 d) {
    position = p;
    direction = d;
}


Line::~Line() {
}

bool Line::intersect(Line & other, IntersectionData& data) {

    float a = (direction.x * (other.position.y - position.y) - direction.y * (other.position.x - position.x));
    float b = (other.direction.x * direction.y - other.direction.y * direction.x);

    if (b == 0)return false;

    data.v = a / b;
    data.u = (other.position.x + data.v * other.direction.x - position.x) / direction.x;

    return true;
}

vec2 Line::operator[](float u) {
    return vec2((float)position.x, (float)position.y) + direction * u;
}

float Line::getXAt(float Y) {
    float u = (Y - position.y) / direction.y;
    return position.x + direction.x * u;
}

float Line::getYAt(float X) {
    float u = (X - position.x) / direction.x;
    return position.y + direction.y * u;
}
