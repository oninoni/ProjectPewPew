#version 420
  
uniform sampler2D tex;  
//uniform uvec2 tilesize; // pixel width and height per tile

in vec2 ftexcoord;
//in vec2 fmtexcoord;

out vec4 outcolor;

void main()
{
    outcolor = texture(tex, ftexcoord);
}