#version 420

uniform float aspect;

layout(location = 0) in vec4 vpos;
layout(location = 8) in vec2 vtexcoord;

out vec2 ftexcoord;

void main()
{
    ftexcoord = vtexcoord;
    gl_Position = vpos;
    gl_Position.x /= aspect;
}