#pragma once

#include "Sprite.h"
#include "Collider.h"
#include "Animator.h"
#include "Common.h"

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
	bool Initialize(ID3D11DeviceContext*, ID3D11Device*, float, float, SPRITE_INFO, float, float);
	void Render(ID3D11DeviceContext*);
	void Release();

	void MovePos(float, float);

	// Getter
	XMFLOAT2 GetPos();


	Sprite* GetSprite();
	ID3D11ShaderResourceView* GetTextureView();

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
};