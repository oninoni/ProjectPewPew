#pragma once
class Location
{
private:
    vec2 position;
    vec2 offset;
    float rotation;

    bool inverted;

    bool matChanged;
    matrix3 mat;

    void doTranslation(vec2 vec);
    void doRotation(float angle);

    void buildMatrix();
public:
    Location(bool inverted = false);
    ~Location();

    vec2 getPosition();
    vec2 getOffset();
    float getRotation();

    void setPosition(vec2 position);
    void setOffset(vec2 offset);
    void setRotation(float rotation);
    
    void translatePosition(vec2 amount);
    void translateOffset(vec2 amount);
    void rotate(float angle);

    matrix3 getMatrix();
    bool getChanged();
};

