#version 420

uniform mat3 view;
uniform mat3 model;

uniform float aspect;

in vec2 vpos;
in vec2 vtexcoord;
//in vec2 vmtexcoord;

out vec2 ftexcoord;
//out vec2 fmtexcoord;

void main()
{
    ftexcoord = vtexcoord;
    //fmtexcoord = vmtexcoord;

    vec3 p = view * model * vec3(vpos, 1);
    gl_Position = vec4(p, 1);
    gl_Position.x /= aspect;
}