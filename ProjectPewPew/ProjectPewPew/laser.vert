#version 420

uniform mat3 model;
uniform mat3 view;

in vec2 vpos;
in vec2 vtexcoord;
in float vlength;
in vec4 vcolor;

out vec2 ftexcoord;
out float flength;
out vec4 fcolor;

void main()
{
    ftexcoord = vtexcoord;
    fcolor = vcolor;
	flength = vlength;

    vec3 p = view * model * vec3(vpos, 1);
    gl_Position = vec4(p, 1);    
}