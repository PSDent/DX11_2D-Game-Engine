#pragma once

#include "Sprite.h"
#include "Collider.h"
#include "Animator.h"
#include "RigidBody2D.h"
#include "Common.h"

#include <vector>
#include <D3D11.h>
#include <d3dcompiler.h>
#include <DirectXMath.h>
#include <string>

class GameObject
{
public:
	GameObject();
	~GameObject();
	GameObject(const GameObject&);
	 
	// Object Method
	bool Initialize(ID3D11DeviceContext*, ID3D11Device*, float, float, float, float);
	void Render(ID3D11DeviceContext*, float);
	void Release();

	void MovePos(float, float);

	template<typename T>
	void CreateComponent();

	template<typename T>
	T GetComponent();

	// Getter
	XMFLOAT2 GetPos();


	Sprite* GetSprite();
	ID3D11ShaderResourceView* GetTextureView();

	void Test();
	//void SetPosition(XMFLOAT3);

	//// Collision Method
	//bool OnCollisionEnter();
	//bool OnCollisionStay();
	//bool OnCollisionExit();

private:
	// GameObject Value
	XMFLOAT2 m_position;
	std::string m_tag;
	std::string m_name;

	float m_scrWidth;
	float m_scrHeight;

	// Component Class
	Sprite *m_sprite;
	Collider *m_collider;
	Animator *m_animator;
	RigidBody2D *m_rigidBody2D;
	std::vector<GameObject> m_childObj;

};

template<typename T>
void GameObject::CreateComponent()
{
	if (typeid(T) == typeid(Animator))
	{
		if (m_animator == NULL)
		{
			m_animator = new Animator(m_sprite);
		}
	}
	else if (typeid(T) == typeid(Sprite))
	{
		if (m_sprite == NULL)
		{
			m_sprite = new Sprite(m_position.x, m_position.y);
		}
	}
	else if (typeid(T) == typeid(Collider))
	{

	}
	else if (typeid(T) == typeid(RigidBody2D))
	{
		if (!m_rigidBody2D)
			m_rigidBody2D = new RigidBody2D(m_position.x, m_position.y);
	}
}

// TO DO
template<typename T>
T GameObject::GetComponent()
{
	if (typeid(T) == typeid(Animator*))
	{
		if(m_animator)
			return (T)m_animator;
	}
	else if (typeid(T) == typeid(Sprite*))
	{
		if (m_sprite)
			return (T)m_sprite;
	}
	else if (typeid(T) == typeid(Collider*))
	{
		if (m_collider)
		return (T)m_collider;
	}
	else if (typeid(T) == typeid(RigidBody2D*))
	{
		if (m_rigidBody2D)
			return (T)m_rigidBody2D;
	}

	return nullptr;
}