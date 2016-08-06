#pragma once
class View
{
private:
    Location* pos;
    vec2 scale;

    Shader* shader;
    int uniformLocation;

    Matrix3 matrix;
    Matrix3 invMatrix;

    bool matChanged;
    bool invMatChanged;

    void buildMatrix();

public:
    View(Shader* shader);
    ~View();

    Matrix3 getMatrix();
    Matrix3 getInvMatrix();

    void uniform(string name);
    void render();

    Location & getPos();
    vec2 getScale();
    void setScale(vec2 scale);
};

