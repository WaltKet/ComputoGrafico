#include "ShaderManager.h"
#include "Platform.h"
#include <glm.hpp>
#include <gtc\matrix_transform.hpp>
#include <gtc\type_ptr.hpp>
ShaderManager* ShaderManager::ptr;

ShaderManager::ShaderManager() : currentShader(nullptr)
{
	LoadShaders("default", vShaderDefault, fShaderDefault);
}

void ShaderManager::LoadShaders(const std::string& name, const std::string& pathV, const std::string& pathF)
{
	Shader* shader1 = new Shader();
	shader1->CreateFromFiles(pathV.c_str(), pathF.c_str());
	shaderList[name] = (*shader1);
	Activate(name);
}

ShaderManager* ShaderManager::getPtr()
{
	if (ptr == nullptr)
	{
		ptr = new ShaderManager();
	}
	return ptr;
}

GLint ShaderManager::GetViewLocation()
{
	return uniformView;
}

GLint ShaderManager::GetProjectionLocation()
{
	return uniformProjection;
}

GLint ShaderManager::GetModelLocation()
{
	return uniformModel;
}

GLint ShaderManager::GetColor1()
{
	return color1;
}

GLint ShaderManager::GetColor2()
{
	return color2;
}
GLint ShaderManager::GetLightPos()
{
	return lightPos;
}
GLint ShaderManager::GetPlayerPosition()
{
	return playerPos;
}

GLint ShaderManager::GetSpecularIntensityLocation()
{
	return uniformSpecularIntensity;
}
glm::mat4 ShaderManager::GetViewMatrix()
{
	return camera->calculateViewMatrix();
}

glm::mat4 ShaderManager::GetProjectionMatrix()
{
	return projection;
}

GLint ShaderManager::GetShininessLocation()
{
	return uniformShininess;
}
void ShaderManager::draw()
{
	if (currentShader != nullptr)
	{
		currentShader->UseShader();
		glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
		glUniformMatrix4fv(uniformView, 1, GL_FALSE, glm::value_ptr(camera->calculateViewMatrix()));
	}
}
void ShaderManager::initShader(Camera* camera)
{
	if (currentShader != nullptr)
	{
		this->camera = camera;
		projection = glm::perspective(45.0f, (float)Platform::GetPtr()->GetWidth() / Platform::GetPtr()->GetHeight(), 0.1f, 1000.0f);


	}

}

void ShaderManager::Activate(const std::string& name)
{
	if (shaderList.find(name) != shaderList.end())
	{
		currentShader = &shaderList[name];
		uniformModel = currentShader->GetModelLocation();
		uniformProjection = currentShader->GetProjectionLocation();
		uniformView = currentShader->GetViewLocation();
		color1 = currentShader->GetColor1();
		color2 = currentShader->GetColor2();
		playerPos = currentShader->GetPlayerPosition();
		lightPos = currentShader->GetLightPos();
	}
}
