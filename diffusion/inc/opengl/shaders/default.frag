#version 330 core
in vec4 vertexCol;

out vec4 fragColor;

void main()
{
	fragColor = vertexCol;
}