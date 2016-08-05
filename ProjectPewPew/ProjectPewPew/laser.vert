#version 420

uniform mat3 model;
uniform mat3 view;

uniform float aspect;

in vec2 vpos;
in vec2 vtexcoord;
in vec4 vcolor;

out vec2 ftexcoord;
out vec4 fcolor;

void main()
{
    ftexcoord = vtexcoord;
    fcolor = vcolor;

    vec3 p = view * model * vec3(vpos, 1);
    gl_Position = vec4(p, 1);
    gl_Position.x /= aspect;      
}