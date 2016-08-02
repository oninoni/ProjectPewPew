#include "stdafx.h"

matrix3::matrix3()
{
    clear();
}                  

matrix3::~matrix3()
{
}

void matrix3::clear(float value)
{
    if (value == 0)
        memset(data, 0, sizeof(data));
    else
        for (int x = 0; x < 3; x++)
            for (int y = 0; y < 3; y++)
                data[x][y] = value;
}

void matrix3::loadIdentity()
{
    clear();
    data[0][0] = 1;
    data[1][1] = 1;
    data[2][2] = 1;
}

float &matrix3::operator()(int x, int y)
{
    return data[x][y];
}

matrix3 matrix3::operator+(matrix3 & other)
{
    matrix3 result;
    for (int x = 0; x < 3; x++)
        for (int y = 0; y < 3; y++)
            result(x, y) = (*this)(x, y) + other(x, y);
    return result;
}

matrix3 matrix3::operator-(matrix3 & other)
{
    matrix3 result;
    for (int x = 0; x < 3; x++)
        for (int y = 0; y < 3; y++)
            result(x, y) = (*this)(x, y) - other(x, y);
    return result;
}

matrix3 matrix3::operator*(matrix3 & other)
{
    matrix3 result;
    for (int x = 0; x < 3; x++)
        for (int y = 0; y < 3; y++)
            result(x, y) = (*this)(0, y) * other(x, 0) + (*this)(1, y) * other(x, 1) + (*this)(2, y) * other(x, 2);
    return result;
}

matrix3 matrix3::operator*(float value)
{
    matrix3 result;
    for (int x = 0; x < 3; x++)
        for (int y = 0; y < 3; y++)
            result(x, y) = (*this)(x, y) * value;
    return result;
}

matrix3 matrix3::transpose()
{
    matrix3 result;
    for (int x = 0; x < 3; x++)
        for (int y = 0; y < 3; y++)
            result(x, y) = (*this)(x, y);
    return result;
}

matrix3 operator*(float value, matrix3 & mat)
{
    return mat * value;
}

vec2 operator*(matrix3 & mat, vec2 vec)
{
    vec2 result;
    result.x = mat(0, 0) * vec.x + mat(1, 0) * vec.y + mat(2, 0);
    result.y = mat(0, 1) * vec.x + mat(1, 1) * vec.y + mat(2, 1);
    return result;
}
