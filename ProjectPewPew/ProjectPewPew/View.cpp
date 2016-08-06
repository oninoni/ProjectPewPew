#include "stdafx.h"

View::View()
{
    pos = new Location(true);
    aspect = 1;
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

void View::render()
{
    if (matChanged || pos->getChanged())
        buildMatrix();
    for (pair<Shader*, int> p : locations)
    {
        p.first->enable();
        glUniformMatrix3fv(p.second, 1, blFalse, matrix.ptr());
    }
}

void View::setAspect(float aspect)
{
    this->aspect = aspect;
    matChanged = true;
}

void View::addShader(Shader * shader)
{
    locations[shader] = shader->getUniformLocation(name);
}

void View::buildMatrix()
{
    matrix = pos->getMatrix();
    Matrix3 m;
    m(0, 0) = 1 / aspect;
    m(1, 1) = 1;
    m(2, 2) = 1;
    matrix = m * matrix;
    invMatChanged = true;
}

Location & View::getPos()
{
    return *pos;
}
