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
    invMatChanged = true;
}

Location & View::getPos()
{
    return *pos;
}
