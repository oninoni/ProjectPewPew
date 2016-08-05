#include "stdafx.h"

void Location::doTranslation(vec2 vec)
{
    Matrix3 m;
    m.loadIdentity();
    m(2, 0) = vec.x;
    m(2, 1) = vec.y;
    mat = mat * m;
}

void Location::doRotation(float angle)
{
    Matrix3 m;
    m.clear();
    m(2, 2) = 1;  
    float r = angle / 180 * (float)PI;
    m(0, 0) = cos(r);
    m(0, 1) = -sin(r);
    m(1, 0) = sin(r);
    m(1, 1) = cos(r);

    mat = mat * m;
}

void Location::buildMatrix()
{
    mat.loadIdentity();
    if (inverted)
    {
        doTranslation(-offset);
        doRotation(-rotation);
        doTranslation(-position);
    }
    else
    {
        doTranslation(position);
        doRotation(rotation);
        doTranslation(offset);
    }
    matChanged = false;
}

Location::Location(bool inverted)
{
    position = vec2(0, 0);
    offset = vec2(0, 0);
    rotation = 0;
    posLowerLimit = vec2(-INFINITY, -INFINITY);
    posUpperLimit = vec2(+INFINITY, +INFINITY);

    matChanged = true;
    this->inverted = inverted;
}

Location::~Location()
{
}

vec2 Location::getPosition()
{
    return position;
}

vec2 Location::getOffset()
{
    return offset;
}

float Location::getRotation()
{
    return rotation;
}

void Location::setPosition(vec2 position)
{
    this->position.x = min(max(position.x, posLowerLimit.x), posUpperLimit.x);
    this->position.y = min(max(position.y, posLowerLimit.y), posUpperLimit.y);
    matChanged = true;
}

void Location::setOffset(vec2 offset)
{
    this->offset = offset;
    matChanged = true;
}

void Location::setRotation(float rotation)
{
    this->rotation = rotation;
    matChanged = true;
}

void Location::setPosLowerLimit(vec2 limit)
{
    posLowerLimit = limit;
    position.x = max(position.x, limit.x);
    position.y = max(position.y, limit.y);
}

void Location::setPosUpperLimit(vec2 limit)
{
    posUpperLimit = limit;
    position.x = min(position.x, limit.x);
    position.y = min(position.y, limit.y);
}

void Location::translatePosition(vec2 amount)
{
    setPosition(position + amount);
    matChanged = true;
}

void Location::translateOffset(vec2 amount)
{
    offset += amount;
    matChanged = true;
}

void Location::rotate(float angle)
{
    rotation += angle;
    matChanged = true;
}

Matrix3 Location::getMatrix()
{
    if (matChanged)
        buildMatrix();
    return mat;
}

bool Location::getChanged()
{
    return matChanged;
}
