#pragma once

#include "Texture.h"
#include "Common.h"
#include "Animation.h"

#include <Windows.h>
#include <D3D11.h>

class Sprite
{
public:
	Sprite(float &, float&);
	~Sprite();
	//Sprite(const Sprite&);

	bool Initialize(ID3D11Device*, ID3D11DeviceContext*, SPRITE_INFO, float, float);
	void Render(ID3D11DeviceContext*, float);
	Texture* GetTexture();
	ID3D11ShaderResourceView* GetTextureView();
	int GetIndex();
	void ChangeTexCoord(int, int);

	void AnimationSet(Animation);

	int* GetTexPosX();
	int* GetTexPosY();

	void SetFlipX(bool);

private:
	void SetSpritePos();
	void SetScreenInfo(float, float);
	void SetSpriteInfo(SPRITE_INFO);
	void InitializeBuffer(ID3D11Device*, ID3D11DeviceContext*);
	void UpdateBuffer(ID3D11DeviceContext*);
	void LoadTexture(ID3D11Device*, WCHAR*);

private:
	int m_index;
	bool m_flipX;
	bool m_flipY;

	float m_time;
	float &m_objPosX;
	float &m_objPosY;

	float m_PosX;
	float m_PosY;

	float m_width;
	float m_height;

	float m_scaleX;
	float m_scaleY;

	float m_scrWidth;
	float m_scrHeight;

	float m_TexWidth;
	float m_TexHeight;
	float m_TexPosX;
	float m_TexPosY;

	Texture *m_texture;
	ANIMATION_INFO *m_animInfo;
	SPRITE_INFO *m_spriteInfo;
	ID3D11Buffer *m_indexBuffer;
	ID3D11Buffer *m_vertexBuffer;
};