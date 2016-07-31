#include "stdafx.h"

Shader::Shader()
{
    program = glCreateProgram();
}

Shader::~Shader()
{
    glDeleteProgram(program);
}

bool Shader::addShaderFromFile(GLShaderType shaderType, string filename)
{
    int shader = glCreateShader(shaderType);

    ifstream shaderFile(filename);
    if (!shaderFile.good())
        return false;

    int size = shaderFile.gcount();
    char* data = new char[size + 1];
    shaderFile.read(data, size);

    cout << "Loading Shader:" << endl;
    cout << data << endl;

    delete[] data;

    glDeleteShader(shader);

    return true;
}

void Shader::enable()
{
    glUseProgram(program);
}

void Shader::disable()
{
    glUseProgram(0);
}
