#pragma once

#include "Texture.h"
#include "Common.h"

#include <Windows.h>
#include <D3D11.h>

class Sprite
{
public:
	Sprite();
	~Sprite();
	//Sprite(const Sprite&);

	bool Initialize(ID3D11Device*, ID3D11DeviceContext*, SPRITE_INFO, float, float, float, float);
	void Render(ID3D11DeviceContext* deviceContext);
	Texture* GetTexture();
	ID3D11ShaderResourceView* GetTextureView();
	int GetIndex();

private:
	void SetSpritePos(float, float);
	void SetScreenInfo(float, float);
	void SetSpriteInfo(SPRITE_INFO);
	void InitializeBuffer(ID3D11Device*, ID3D11DeviceContext*);
	void UpdateBuffer(ID3D11DeviceContext*);
	void LoadTexture(ID3D11Device*, WCHAR*);

private:
	int m_index;
	float m_PosX;
	float m_PosY;
	float m_scrWidth;
	float m_scrHeight;

	Texture *m_texture;
	SPRITE_INFO *m_spriteInfo;
	ID3D11Buffer *m_indexBuffer;
	ID3D11Buffer *m_vertexBuffer;
	
};