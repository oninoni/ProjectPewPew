#pragma once
struct IntersectionData {
    float u;
    float v;
};

struct Line {
    Line();
    Line(vec2 p, vec2 d);
    ~Line();

    bool intersect(Line &other, IntersectionData& data);
    vec2 operator[](float u);

    vec2 position;
    vec2 direction;
};

