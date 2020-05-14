#version 330

layout (location = 0) in vec3 pos;

out vec4 vCol;

uniform mat4 model;
uniform mat4 projection;
uniform mat4 view;
uniform vec3 color1;
uniform vec3 color2;

uniform vec3 playerPosition;

void main()
{
	gl_Position = projection * view * model * vec4(pos, 1.0);
	if (distance(playerPosition,(model * vec4(pos, 1.0)).xyz) > 5.0f)
	{
		vCol = vec4(color1, 1.0f);
	}
	else 
	{
		vCol = vec4(color2, 1.0f);
	}
}