#pragma once
class Matrix3
{
private:
    float data[3][3];

public:
    Matrix3();
    ~Matrix3();

    void clear(float value = 0);
    void loadIdentity();

    float * ptr();

    float &operator()(int x, int y);

    // matrix with matrix
    Matrix3 operator+(Matrix3 &other);
    Matrix3 operator-(Matrix3 &other);
    Matrix3 operator*(Matrix3 &other);
    
    // matrix with value
    Matrix3 operator*(float value);
    friend Matrix3 operator*(float value, Matrix3 &mat);

    // vector with matrix
    friend vec2 operator*(vec2 vec, Matrix3 &mat);

    Matrix3 transpose();
};

