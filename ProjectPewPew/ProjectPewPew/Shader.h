#pragma once
class Shader
{
public:
    struct Attribute {
        int count;
        string name;
        GLDataType type;

        Attribute(int count, string name, GLDataType type)
        {
            this->count = count;
            this->name = name;
            this->type = type;
        }
    };

private:
    int program;
    string_hashmap<int*> locations;

    vector<Attribute> attributes;

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

    void addAttribute(int count, string name, GLDataType type = dtFloat);

    int getAttribCount();
    Attribute getAttribute(int i);

    void enable();

    static void disable();
};

