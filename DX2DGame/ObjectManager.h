#pragma once

#include <vector>
#include <iterator>

#include "Common.h"
#include "GameObject.h"
#include "Player.h"
#include "Input.h"

class ObjectManager
{
public:
	ObjectManager();
	~ObjectManager();
	
	void Initialize(ID3D11DeviceContext*, ID3D11Device*, float, float, Input*);
	void CreateObject(float, float, SPRITE_INFO);
	void Render();

	void Release();

private:
	void InsertObject(); 
	void FirstCreate();


private:
	ID3D11DeviceContext *m_deviceContext;
	ID3D11Device *m_device;
	float m_scrWidth;
	float m_scrHeight;

	Input *m_input;
	std::vector<GameObject*> *m_objContainer;
	std::vector<GameObject*>::iterator iter;
};

