#pragma once
#include "CGE/Base/GameState.h"
#include "CGE/Base/GameStateManager.h"
#include "CGE/Graphic/Mesh.h"
#include "CGE/Graphic/Shader.h"
#include "CGE/Base/ShaderManager.h"
#include<vector>
class Menu : public GameState
{
private:
	Platform* platform;
	GameStateManager* manager;

	std::vector<Mesh*> meshList;
	ShaderManager* shaderManager;
	Camera camera;
	float lightangle = 0;
	bool key;
public:
	Menu();
	~Menu();
	void Init() override;
	void Draw() override;
	bool Input(std::map<int, bool> keys) override;
	bool MouseInput(int x, int y, bool leftbutton);
	void Update() override;
	void Close() override;

	void LoadShaders();
	void LoadModels();
};