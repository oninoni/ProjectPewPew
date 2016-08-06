#include "stdafx.h"

View::View()
{
    pos = new Location(true);
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

void View::addShader(Shader * shader)
{
    locations[shader] = shader->getUniformLocation(name);
}

void View::buildMatrix()
{
    matrix = pos->getMatrix();       
    invMatChanged = true;
}

Location & View::getPos()
{
    return *pos;
}
