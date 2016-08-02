#pragma once
#include "Attribute.h"
class VAO {
private:
    GLuint vao;
    GLuint vbo;

    void* pvbo;
    DWORD vbopos;

    GLRenderMode renderMode;

    DWORD size;
    DWORD maxSize;
    DWORD stride;

    vector<Attribute> attributes;
    Shader* shader;

    static VAO* boundVAO;

protected:
    Shader* getShader();

    virtual void beforeRender();
    virtual void afterRender();
public:
	VAO(Shader* shader, GLRenderMode renderMode = rmTriangles);
	~VAO();

    void bind();
    void unbind();

    void addAttribute(DWORD count, string name, GLDataType dataType = dtFloat);
    void genAttributes();

    void generate(DWORD maxSize, GLBufferUsage usage);

    bool map(GLBufferAccess access);
    void unmap();

    bool addVertex(void *data);

    void render();
};

