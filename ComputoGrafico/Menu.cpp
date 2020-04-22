#include "Menu.h"
#include<iostream>
#include <glm.hpp>
#include <gtc\matrix_transform.hpp>
#include <gtc\type_ptr.hpp>

void calcAverageNormals(unsigned int* indices, unsigned int indiceCount, GLfloat* vertices, unsigned int verticeCount,
	unsigned int vLength, unsigned int normalOffset)
{
	for (size_t i = 0; i < indiceCount; i += 3)
	{
		unsigned int in0 = indices[i] * vLength;
		unsigned int in1 = indices[i + 1] * vLength;
		unsigned int in2 = indices[i + 2] * vLength;
		glm::vec3 v1(vertices[in1] - vertices[in0], vertices[in1 + 1] - vertices[in0 + 1], vertices[in1 + 2] - vertices[in0 + 2]);
		glm::vec3 v2(vertices[in2] - vertices[in0], vertices[in2 + 1] - vertices[in0 + 1], vertices[in2 + 2] - vertices[in0 + 2]);
		glm::vec3 normal = glm::cross(v1, v2);
		normal = glm::normalize(normal);

		in0 += normalOffset; in1 += normalOffset; in2 += normalOffset;
		vertices[in0] += normal.x; vertices[in0 + 1] += normal.y; vertices[in0 + 2] += normal.z;
		vertices[in1] += normal.x; vertices[in1 + 1] += normal.y; vertices[in1 + 2] += normal.z;
		vertices[in2] += normal.x; vertices[in2 + 1] += normal.y; vertices[in2 + 2] += normal.z;
	}

	for (size_t i = 0; i < verticeCount / vLength; i++)
	{
		unsigned int nOffset = i * vLength + normalOffset;
		glm::vec3 vec(vertices[nOffset], vertices[nOffset + 1], vertices[nOffset + 2]);
		vec = glm::normalize(vec);
		vertices[nOffset] = vec.x; vertices[nOffset + 1] = vec.y; vertices[nOffset + 2] = vec.z;
	}
}

Menu::Menu()
{

}

Menu::~Menu()
{
}

void Menu::Init()
{
	std::cout << " Menu Init" << std::endl;
	this->platform = Platform::GetPtr();
	this->manager = GameStateManager::GetPtr();
	camera = Camera(glm::vec3(0, 0, 0.6f), glm::vec3(0.0f, 1.0f, 0.0f), 0.0f, 0.0f, 55.0f, 0.1f);
	shaderManager = ShaderManager::getPtr();
	shaderManager->initShader(&camera);
	shaderManager->LoadShaders("OneColor", "Assets/Shaders/OneColor.vert", "Assets/Shaders/OneColor.frag");
	shaderManager->LoadShaders("gouraud-shader", "Assets/Shaders/gouraud-shader.vert", "Assets/Shaders/gouraud-shader.frag");
	LoadModels();
	
}

void Menu::LoadModels()
{
	unsigned int indices[] = {
<<<<<<< HEAD
				0,1,2,
				2,3,0,
				0,4,3,
				4,7,3,
				3,7,6,
				6,3,2
	};

	GLfloat vertices[] = {
		// front
		-1.0, -1.0,  1.0, 0.0f, 0.0f,		0.0f, 0.0f, 0.8f,1.0f, 0.0f, 0.0f,//0
		1.0, -1.0,  1.0,1.0f, 0.0f,		0.0f, 0.0f, 0.0f,1.0f, 0.0f, 0.0f,//1
		1.0,  1.0,  1.0,0.0f, 1.0f,		0.0f, 0.0f, 0.0f,1.0f, 0.0f, 0.0f,//2
		-1.0,  1.0,  1.0,1.0f, 0.0f,		0.0f, 0.0f, 0.0f,1.0f, 0.0f, 0.0f,//3
		// back
		-1.0, -1.0, -1.0,1.0f, 1.0f,		0.0f, 0.0f, 0.0f,1.0f, 0.0f, 0.0f,//4
		1.0, -1.0, -1.0,1.0f, 0.0f,		0.0f, 0.0f, 0.0f,1.0f, 0.0f, 0.0f,//5
		1.0,  1.0, -1.0,1.0f, 1.0f,		0.0f, 0.0f, 0.0f,1.0f, 0.0f, 0.0f,//6
		-1.0,  1.0, -1.0,0.0f, 1.0f,		0.7f, -0.7f, 0.0f,1.0f, 0.0f, 0.0f,//7
=======
	0,1,2,
	2,3,1,
	0,4,5,
	1,5,0,
	5,6,4,
	6,7,5,
	2,6,1,
	1,5,6,
	2,6,7,
	3,7,2,
	0,4,3,
	3,7,0
		};

	GLfloat vertices[] = {
	//0.0f, 0.0f,0.0f,
	//-0.6f, 0.81f, 0.0f,
	//-1.4f, 0.23f, 0.0f,
	//-0.8f, -0.5f, 0.0f,
	//0.0f, 0.0f,1.0f,
	//-0.6f, 0.81f, 1.0f,
	//-1.4f, 0.23f, 1.0f,
	//-0.8f, -0.5f, 1.0f,
		0.0f,0.0f,0.0f,
		1.0f,0.0f,0.0f,
		0.0f,1.0f,0.0f,
		1.0f,1.0f,0.0f,
		0.0f,0.0f,0.38f,
		1.0f,0.0f,0.38f,
		0.0f,1.0f,0.38f,
		1.0f,1.0f,0.38f
>>>>>>> Se dibuja un cubo 1x1x1
	};
	calcAverageNormals(indices, 18, vertices, 88, 11, 5);
	Mesh *obj1 = new Mesh();
<<<<<<< HEAD
	obj1->CreateMesh(vertices, indices, 88, 18, 11);
=======
	obj1->CreateMesh(vertices, indices, 24, 36);
>>>>>>> Se dibuja un cubo 1x1x1
	meshList.push_back(obj1);
}
void Menu::LoadShaders()
{
	
}

void Menu::Draw()
{
	platform->RenderClear();
	shaderManager->Activate("gouraud-shader");
	shaderManager->draw();
	glm::mat4 model(1);
<<<<<<< HEAD
	GLint uniformModel = shaderManager->GetModelLocation();
=======
	
>>>>>>> Se dibuja un cubo 1x1x1
	model = glm::translate(model, glm::vec3(0.0f, 0.0f, -2.5f));
	model = glm::rotate(model, 100.0f, glm::vec3(1.0f, 1.0f, 0.0f));
	model = glm::scale(model, glm::vec3(0.4f, 0.4f, 1.0f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	meshList[0]->RenderMesh();


	shaderManager->Activate("default");
	shaderManager->draw();
	uniformModel = shaderManager->GetModelLocation();
	model = glm::translate(model, glm::vec3(10.0f, 0.0f, -8.5f));
	model = glm::scale(model, glm::vec3(0.7f, 0.4f, 1.0f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	meshList[0]->RenderMesh();

	platform->RenderPresent();
}
bool Menu::MouseInput(int x, int y, bool leftbutton)
{
	if (x != -1 || y != -1)
		camera.mouseControl(x, y);

	return false;
}

bool Menu::Input(std::map<int, bool> keys)
{
	camera.keyControl(keys, platform->GetDeltaTime());
	return false;
}


void Menu::Update()
{
}

void Menu::Close()
{
	std::cout << " Close Init" << std::endl;
}