#pragma once
class matrix3
{
private:
    float data[3][3];

public:
    matrix3();
    ~matrix3();

    void clear(float value = 0);
    void loadIdentity();

    float * ptr();

    float &operator()(int x, int y);

    // matrix with matrix
    matrix3 operator+(matrix3 &other);
    matrix3 operator-(matrix3 &other);
    matrix3 operator*(matrix3 &other);
    
    // matrix with value
    matrix3 operator*(float value);
    friend matrix3 operator*(float value, matrix3 &mat);

    // vector with matrix
    friend vec2 operator*(vec2 vec, matrix3 &mat);

    matrix3 transpose();
};

