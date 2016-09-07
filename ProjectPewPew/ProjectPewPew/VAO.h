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

	// mostly not neccessary outside of this class
    void bind();
    void unbind();   

    // get memory in the GPU
    void generate(DWORD maxSize, GLBufferUsage usage);

	// copies data between GPU and RAM, enabling addVertex() between map and unmap
    bool map(GLBufferAccess access);
    void unmap();

    bool addVertex(void *data);
	
	// alternative to map/unmap if VAO size is constant
	bool forceSize(int count); 
	
	// change data directly in the VAO without having to map it first
	bool changeVertex(DWORD index, void* data);
	bool changeVerticies(DWORD index, DWORD count, void* data);
	bool changeAttribute(DWORD index, DWORD attribute, void* data);

    Location& getPos();
    void render();
};

