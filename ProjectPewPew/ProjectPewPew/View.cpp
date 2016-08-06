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

Matrix3 View::getMatrix()
{
    if (matChanged || pos->getChanged())
        buildMatrix();
    return matrix;
}

Matrix3 View::getInvMatrix()
{
    if (invMatChanged || pos->getChanged())
        invMatrix = getMatrix().inverse();
    return invMatrix;
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
    invMatChanged = true;
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
