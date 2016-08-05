#pragma once

template <typename type> 
struct gvec2 sealed
{
    gvec2();
    gvec2(type x, type y);
    
    gvec2<type> operator+(const gvec2<type> &other);
    gvec2<type> operator+(type value);
    template<typename t>
    friend gvec2<t> operator+(t value, const gvec2<t> &vec);

    gvec2<type> operator-();

    gvec2<type> operator-(const gvec2<type> &other);
    gvec2<type> operator-(type value);

    gvec2<type> operator*(const gvec2<type> &other);
    gvec2<type> operator*(type value);
    
    gvec2<type> operator/(const gvec2<type> &other);
    gvec2<type> operator/(type value);

    bool operator==(const gvec2<type> &other);
    bool operator!=(const gvec2<type> &other);

    gvec2<type> operator+=(const gvec2<type> &other);
    gvec2<type> operator-=(const gvec2<type> &other);

    gvec2<type> vectorTo(const gvec2<type> &other);

    gvec2<type> cross();

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
inline gvec2<type> gvec2<type>::operator+(type value)
{
    return gvec2<type>(x + value, y + value);
}

template<typename t>
gvec2<t> operator+(t value, const gvec2<t> &vec)
{
    return gvec2<t>(value + vec.x, value + vec.y);
}

template<typename type>
inline gvec2<type> gvec2<type>::operator-()
{
    return gvec2<type>(-x, -y);
}

template<typename type>
inline gvec2<type> gvec2<type>::operator-(const gvec2<type> &other)
{
    return gvec2<type>(x - other.x, y - other.y);
}

template<typename type>
inline gvec2<type> gvec2<type>::operator-(type value)
{
    return gvec2<type>(x - value, y - value);
}

template<typename type>
inline gvec2<type> gvec2<type>::operator*(const gvec2<type> &other)
{
    return gvec2<type>(x * other.x, y * other.y);
}

template<typename type>
inline gvec2<type> gvec2<type>::operator*(type value)
{
    return gvec2<type>(x * value, y * value);
}

template<typename type>
inline gvec2<type> gvec2<type>::operator/(const gvec2<type> &other)
{
    return gvec2<type>(x / other.x, y / other.y);
}

template<typename type>
inline gvec2<type> gvec2<type>::operator/(type value)
{
    return gvec2<type>(x / value, y / value);
}

template<typename type>
inline bool gvec2<type>::operator==(const gvec2<type>& other)
{
    return x == other.x && y == other.y;
}

template<typename type>
inline bool gvec2<type>::operator!=(const gvec2<type>& other)
{
    return !(*this == other);
}

template<typename type>
inline gvec2<type> gvec2<type>::operator+=(const gvec2<type>& other)
{
    x += other.x;
    y += other.y;
    return *this;
}

template<typename type>
inline gvec2<type> gvec2<type>::operator-=(const gvec2<type>& other)
{
    x -= other.x;
    y -= other.y;
    return *this;
}

template<typename type>
inline gvec2<type> gvec2<type>::vectorTo(const gvec2<type> &other)
{
    return gvec2<type>(this* - other);
}

template<typename type>
inline gvec2<type> gvec2<type>::cross()
{
    return gvec2<type>(-y, x);
}

template<typename type>
inline ostream & operator<<(ostream &stream, gvec2<type> vec)
{
    stream << "[" << vec.x << "|" << vec.y << "]";
    return stream;
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
