#include "GameObject.h"

GameObject::GameObject()
{
	m_sprite = NULL;
	m_collider = NULL;
	m_animator = NULL;
}

GameObject::~GameObject() { }
GameObject::GameObject(const GameObject& a) {}

bool GameObject::Initialize(ID3D11DeviceContext *deviceContext, ID3D11Device* device, float posX, float posY, float scrWidth, float scrHeight)
{
	m_position.x = posX;
	m_position.y = posY;

	//m_sprite = new Sprite(m_position.x, m_position.y);

	//m_sprite->Initialize(device, deviceContext, spriteInfo, posX, posY, scrWidth, scrHeight);
	return true;
}

void GameObject::Test()
{
	m_position.x += 0.5f;
	m_position.y += 0.5f;
}

void GameObject::MovePos(float deltaX, float deltaY)
{
	m_position.x += deltaX;
	m_position.y += deltaY;
}

XMFLOAT2 GameObject::GetPos()
{
	return m_position;
}

ID3D11ShaderResourceView* GameObject::GetTextureView()
{
	return m_sprite->GetTextureView();
}

Sprite* GameObject::GetSprite()
{
	return m_sprite;
}

void GameObject::Render(ID3D11DeviceContext *deviceContext)
{
	//Test();
	if(m_sprite)
		m_sprite->Render(deviceContext);
	//if (m_animator)
	//	m_animator->Frame();
	//if (m_collider)
	//	m_collider->foo();
}

void GameObject::Release()
{
	if (m_sprite)
	{

	}

	if (m_collider)
	{

	}

	if (m_animator)
	{

	}
}