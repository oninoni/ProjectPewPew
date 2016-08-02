#version 420

in vec2 vpos;
in vec2 vtexcoord;

out vec2 ftexcoord;

void main()
{
    ftexcoord = vtexcoord;
    gl_Position = vec4(vpos, 0, 1);
}