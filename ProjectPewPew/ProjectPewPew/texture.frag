#version 420
  
uniform sampler2D tex;  
//uniform uvec2 tilesize; // pixel width and height per tile

in vec2 ftexcoord;
//in vec2 fmtexcoord;

out vec4 outcolor;

void main()
{
/*
    vec2 reltc = ftexcoord - fmtexcoord; // -0.5/mapsize > +0.5/mapsize
    vec2 border =  / tilesize;
    reltc = clamp(reltc, -0.5 + border, +0.5 - border);
*/
    outcolor = texture(tex, ftexcoord);
}