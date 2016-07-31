#pragma once
class Shader
{
private:
    int program;

public:
    Shader();
    ~Shader();

    bool addShaderFromFile(GLShaderType shaderType, string filename);

    void enable();
    static void disable();
};

