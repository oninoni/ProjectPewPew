#include "stdafx.h"

View::View(Shader* shader)
{
    pos = new Location(true);
    this->shader = shader;     
}

View::~View()
{
    delete pos;
}

void View::uniform(string name)
{
    uniformLocation = shader->getUniformLocation(name);
}

void View::render()
{
    if (matChanged || pos->getChanged())
        buildMatrix();
    glUniformMatrix3fv(uniformLocation, 1, blFalse, matrix.ptr());
}

void View::buildMatrix()
{
    matrix = pos->getMatrix();
    matrix(0, 0) *= scale.x;
    matrix(1, 0) *= scale.x;
    matrix(2, 0) *= scale.x;
    matrix(0, 1) *= scale.y;
    matrix(1, 1) *= scale.y;
    matrix(2, 1) *= scale.y;
    matChanged = false;
}

Location & View::getPos()
{
    return *pos;
}

vec2 View::getScale()
{
    return scale;
}

void View::setScale(vec2 scale)
{
    this->scale = scale;
    matChanged = true;
}
