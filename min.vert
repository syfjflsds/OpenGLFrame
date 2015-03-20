#version 330
layout(location = 0) in vec4 position;
//layout(location = 1) in vec4 color;
uniform vec2 offset;
uniform mat4x4 modelViewProjectionMatrix;

out vec4 theColor;
void main()
{
	//vec4 useOffset = vec4(offset.x, offset.y, 0.0, 0.0);
	//gl_Position = modelViewProjectionMatrix * gl_Position; // + useOffset;
	//gl_Position = position - vec4(0, 0, 4, 0);
	//gl_Position = vec4(position.x, position.y, position.z, 1);
	//gl_Position = vec4(position.x, position.y, position.z + 3, 1);
	//gl_Position = vec4(position.x, position.y, position.z, 1);
	//gl_Position = modelViewProjectionMatrix * position;
	//theColor = color;
	gl_Position = modelViewProjectionMatrix * position;
}