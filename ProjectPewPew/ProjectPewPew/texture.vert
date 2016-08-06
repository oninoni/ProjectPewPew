#version 420

uniform mat3 view;
uniform mat3 model;

in vec2 vpos;
in vec2 vtexcoord;
in vec2 vminborder;
in vec2 vmaxborder;

out vec2 ftexcoord; 
out vec2 fminborder;
out vec2 fmaxborder;

void main()
{
    ftexcoord = vtexcoord;
    fminborder = vminborder;
    fmaxborder = vmaxborder;

    vec3 p = view * model * vec3(vpos, 1);
    gl_Position = vec4(p, 1);;
}