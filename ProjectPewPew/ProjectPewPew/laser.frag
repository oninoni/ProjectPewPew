#version 420

in vec2 ftexcoord;
in float flength;
in vec4 fcolor;

out vec4 outcolor;

void main()
{
    float alpha = sqrt(1 - ftexcoord.x * ftexcoord.x) * (1 - ftexcoord.y);
    outcolor = alpha * fcolor; 
}