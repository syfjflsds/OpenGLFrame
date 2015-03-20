//#version 330
#version 130

out vec4 outputColor;
in vec4 theColor;
void main()
{
//	outputColor = theColor;
//	float lerpValue = gl_FragCoord.y / 600.0f;
//	outputColor = mix(vec4(1.0f, 1.0f, 1.0f, 1.0f), vec4(0.0f, 0.0f, 0.0f, 1.0f), lerpValue);
	//int number = int(gl_FragCoord).y % 5;
	int temp = int(gl_FragCoord.y);
	int number = temp % 20;
	float colorBase = 1.0f / (number + 1);
	outputColor = vec4(colorBase, colorBase, colorBase, 1.0f);
}