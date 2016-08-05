#version 420

uniform mat3 model;
uniform mat3 view;

in vec2 vpos;
in vec2 vtexcoord;
in vec4 vcolor;

out vec2 ftexcoord;
out vec2 fcolor;

void main()
{
    ftexcoord = vtexcoord;
    fcolor = vcolor;

    gl_Position = model * view * vpos;       
}