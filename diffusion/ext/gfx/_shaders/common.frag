#version 330 core
in float TexID;
in vec2 TexCoords;

out vec4 fragColor;

uniform sampler2D ourTex[2];

void main()
{
	int index = int(TexID);
	fragColor = texture(ourTex[index], TexCoords);
}