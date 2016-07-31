#version 420

uniform vec3 color;

out vec4 outcolor;

void main()
{
    outcolor = vec4(color, 1);    
}