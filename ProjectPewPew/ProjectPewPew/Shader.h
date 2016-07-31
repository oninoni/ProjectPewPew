#pragma once
class Shader
{
private:
    int program;
    string_hashmap<int*> locations;

    static Shader* activeShader;

    bool checkShaderErrors(string shaderName, int shader);
    bool checkProgramErrors();

public:
    Shader();
    ~Shader();

    bool addShaderFromFile(GLShaderType shaderType, string filename);
    bool link();

    bool loadVertFragShader(string filename);

    int getUniformLocation(string name);
    int getAttribLocation(string name);

    void enable();
    static void disable();
};

