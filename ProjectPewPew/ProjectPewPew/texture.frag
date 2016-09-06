#version 420
  
uniform sampler2D tex;

in vec2 ftexcoord;
in vec2 fminborder;
in vec2 fmaxborder;

out vec4 outcolor;

void main()
{
	outcolor = texture(tex, clamp(ftexcoord, fminborder, fmaxborder));
}