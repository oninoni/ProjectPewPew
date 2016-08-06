#pragma once
#include "Attribute.h"
class VAO {
private:
    GLuint vao;
    GLuint vbo;

    int location;

    void* pvbo;
    DWORD vbopos;

    GLRenderMode renderMode;

    DWORD size;
    DWORD maxSize;
    DWORD stride;

    vector<Attribute> attributes;
    Shader* shader;

    Location pos;

    void addAttribute(DWORD count, string name, GLDataType dataType = dtFloat);
    void genAttributes();

    static VAO* boundVAO;

    const string name = "model";

protected:
    Shader* getShader();

    virtual void beforeRender();
    virtual void afterRender();
public:
	VAO(Shader* shader, GLRenderMode renderMode = rmTriangles);
	~VAO();

    void bind();
    void unbind();   
    
    void generate(DWORD maxSize, GLBufferUsage usage);

    bool map(GLBufferAccess access);
    void unmap();

    bool addVertex(void *data);

    Location& getPos();
    void render();
};

