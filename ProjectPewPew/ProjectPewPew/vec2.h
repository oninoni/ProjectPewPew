#pragma once

template <typename type> 
struct gvec2 sealed
{
    gvec2();
    gvec2(type x, type y);

    gvec2<type> operator+(const gvec2<type> &other);
    gvec2<type> operator+(const type value);

    gvec2<type> operator-(const gvec2<type> &other);
    gvec2<type> operator-(const type value);

    gvec2<type> operator*(const gvec2<type> &other);
    gvec2<type> operator*(const type value);

    gvec2<type> operator/(const gvec2<type> &other);
    gvec2<type> operator/(const type value);

    gvec2<type> vectorTo(const gvec2<type> &other);

    float lengthSqr();
    float length();

    type x, y;
};

typedef gvec2<int> ivec2;
typedef gvec2<unsigned int> cvec2;

typedef gvec2<float> vec2;
typedef gvec2<float> texcoord;

template<typename type>
inline gvec2<type>::gvec2()
{
    x = 0;
    y = 0;
}

template<typename type>
inline gvec2<type>::gvec2(type x, type y)
{
    this->x = x;
    this->y = y;
}

template<typename type>
inline gvec2<type> gvec2<type>::operator+(const gvec2<type> &other)
{
    return gvec2<type>(x + other.x, y + other.y);
}

template<typename type>
inline gvec2<type> gvec2<type>::operator+(const type value)
{
    return gvec2<type>(x + value, y + value);
}

template<typename type>
inline gvec2<type> gvec2<type>::operator-(const gvec2<type> &other)
{
    return gvec2<type>(x - other.x, y - other.y);
}

template<typename type>
inline gvec2<type> gvec2<type>::operator-(const type value)
{
    return gvec2<type>(x - value, y - value);
}

template<typename type>
inline gvec2<type> gvec2<type>::operator*(const gvec2<type> &other)
{
    return gvec2<type>(x * other.x, y * other.y);
}

template<typename type>
inline gvec2<type> gvec2<type>::operator*(const type value)
{
    return gvec2<type>(x * value, y * value);
}

template<typename type>
inline gvec2<type> gvec2<type>::operator/(const gvec2<type> &other)
{
    return gvec2<type>(x / other.x, y / other.y);
}

template<typename type>
inline gvec2<type> gvec2<type>::operator/(const type value)
{
    return gvec2<type>(x / value, y / value);
}

template<typename type>
inline gvec2<type> gvec2<type>::vectorTo(const gvec2<type> &other)
{
    return gvec2<type>(this* - other);
}

template<typename type>
inline float gvec2<type>::lengthSqr()
{
    return x * x + y * y;
}

template<typename type>
inline float gvec2<type>::length()
{
    return sqrt(lengthSqr());
}
