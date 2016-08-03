#pragma once
class View
{
private:
    Location* pos;
    vec2 scale;

    Shader* shader;
    int uniformLocation;

    matrix3 matrix;

    bool matChanged;

public:
    View(Shader* shader);
    ~View();

    void uniform(string name);

    void render();

    void buildMatrix();

    Location * getPos();
    vec2 getScale();
    void setScale(vec2 scale);
};

