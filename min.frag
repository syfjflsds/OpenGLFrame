#version 120

varying vec4 varyColor;
void main()
{
	float color = abs(sin(gl_FragCoord.x)); 
	gl_FragColor = vec4(color, color, color, 1.0);//varyColor;
}