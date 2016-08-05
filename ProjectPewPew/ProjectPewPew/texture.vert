#version 420

uniform mat3 view;
uniform mat3 model;

uniform float aspect;

in vec2 vpos;
in vec2 vtexcoord;

out vec2 ftexcoord;

void main()
{
    ftexcoord = vtexcoord;
    vec3 p = view * model * vec3(vpos, 1);
    gl_Position = vec4(p.xy, 0, 1);
    gl_Position.x /= aspect;
}