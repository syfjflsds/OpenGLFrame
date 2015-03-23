#version 120
attribute vec4 position;
attribute vec4 color;
uniform vec2 offset;
uniform mat4x4 modelViewProjectionMatrix;
varying vec4 varyColor;

void main()
{
	varyColor = color;
	gl_Position = modelViewProjectionMatrix * position;
}