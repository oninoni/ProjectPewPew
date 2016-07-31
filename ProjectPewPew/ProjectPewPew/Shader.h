#pragma once
class Shader
{
private:
    int program;

    static Shader* activeShader;

    bool checkShaderErrors(string shaderName, int shader);
    bool checkProgramErrors();

public:
    Shader();
    ~Shader();

    bool addShaderFromFile(GLShaderType shaderType, string filename);
    bool link();

    bool loadVertFragShader(string filename);

    // TODO: Possseidon GetUniformLocation and save in string hashtable


    void enable();
    static void disable();
};

