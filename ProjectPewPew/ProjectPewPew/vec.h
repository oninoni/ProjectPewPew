#pragma once

template <int n, typename t> 
class vec
{
private:
    t[n] value;
public:
    vec();
    vec(&vec vec);

    ~vec();
};

