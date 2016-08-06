#version 420

in vec2 ftexcoord;
in vec4 fcolor;

out vec4 outcolor;

void main()
{
    float alpha = sqrt(1 - ftexcoord.x * ftexcoord.x);
    outcolor = alpha * fcolor; 
}