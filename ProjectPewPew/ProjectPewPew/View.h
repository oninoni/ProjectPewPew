#pragma once
class View
{
private:
    Location* pos;

    unordered_map<Shader*, int> locations;
    
    Matrix3 matrix;
    Matrix3 invMatrix;

    bool matChanged;
    bool invMatChanged;

    void buildMatrix();

    const string name = "view";

public:
    View();
    ~View();

    Matrix3 getMatrix();
    Matrix3 getInvMatrix();

    void addShader(Shader* shader);
    
    void render();

    Location & getPos();
};

