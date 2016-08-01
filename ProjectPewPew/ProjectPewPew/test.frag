#version 420
  
uniform sampler2D tex;

in vec2 ftexcoord;

out vec4 outcolor;

void main()
{
    outcolor = texture(tex, ftexcoord);    
}