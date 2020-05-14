#version 330

in vec3 FragPos;
in vec3 Normal1;
out vec4 colour;
uniform vec3 myLightPosition;

void main()
{
	float intensity;
	vec4 color;
	intensity = dot(myLightPosition, normalize(Normal1));

	if (intensity > 0.95)
		color = vec4(1.0,0.3,0.3,1.0);
	else if (intensity > 0.5)
		color = vec4(0.0,1.0,1.0,1.0);
	else if (intensity > 0.25)
		color = vec4(1.0,0.0,1.0,1.0);
	else
		color = vec4(0.4,0.1,0.1,1.0);
	colour = color;

}