#include "ObjectManager.h"



ObjectManager::ObjectManager()
{
	m_objContainer = NULL;
	m_deviceContext = NULL;
	m_device = NULL;
}


ObjectManager::~ObjectManager()
{
}

void ObjectManager::Initialize(ID3D11DeviceContext* deviceContext, ID3D11Device* device, float width, float height, Input* input)
{
	m_objContainer = new std::vector<GameObject*>();

	m_deviceContext = deviceContext;
	m_device = device;
	m_scrWidth = width;
	m_scrHeight = height;
	m_input = input;

	FirstCreate();
}

void ObjectManager::FirstCreate()
{
	CreateObject(0, 0);
}

void ObjectManager::InsertObject()
{

}

void ObjectManager::CreateObject(float posX, float posY)
{
	Player *temp = new Player();
	temp->Initialize(m_deviceContext, m_device, posX, posY, m_scrWidth, m_scrHeight, m_input);
	
	temp->CreateComponent<Sprite>();
	temp->GetSprite()->Initialize(m_device, m_deviceContext, SPRITE_INFO{ Cat, 1, 1 }, m_scrWidth, m_scrHeight);
	
	temp->CreateComponent<Animator>();
	temp->GetComponent<Animator*>()->AddAnim(Animation("Test", ANIMATION_INFO{ Cat, 0.1f, 0.1f, 1, 10, 0.5f }));
	
	m_objContainer->push_back(temp);

	/*GameObject *temp = new GameObject();
	temp->Initialize(m_deviceContext, m_device, posX, posY, spriteInfo, m_scrWidth, m_scrHeight);
	m_objContainer->push_back(temp);*/
}

void ObjectManager::Render(float deltaTime)
{
	for (iter = m_objContainer->begin(); iter != m_objContainer->end(); ++iter)
	{
		(*iter)->Render(m_deviceContext, deltaTime);
		ID3D11ShaderResourceView* temp = (*iter)->GetTextureView();
		m_deviceContext->PSSetShaderResources(0, 1, &temp);
		m_deviceContext->DrawIndexed((*iter)->GetSprite()->GetIndex(), 0, 0);
	}
}

void ObjectManager::Release()
{

}
