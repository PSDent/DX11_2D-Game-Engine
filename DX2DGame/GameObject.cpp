#include "GameObject.h"

GameObject::GameObject()
{
	m_sprite = NULL;
	m_collider = NULL;
	m_animator = NULL;
}

GameObject::~GameObject() { }
GameObject::GameObject(const GameObject& a) {}

bool GameObject::Initialize(ID3D11DeviceContext *deviceContext, ID3D11Device* device, float posX, float posY, SPRITE_INFO spriteInfo, float scrWidth, float scrHeight)
{
	m_sprite = new Sprite();
	m_sprite->Initialize(device, deviceContext, spriteInfo, posX, posY, scrWidth, scrHeight);

	m_position.x = posX;
	m_position.y = posY;

	return true;
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
	m_sprite->Render(deviceContext);
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