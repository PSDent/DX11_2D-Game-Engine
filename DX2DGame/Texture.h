#pragma once
#include <D3D11.h>
#include <d3dcompiler.h>
#include <D3DX11tex.h>

class Texture
{
public:
	Texture();
	~Texture();

	bool SetTexture(ID3D11Device* ,WCHAR*);
	void Release();

	ID3D11ShaderResourceView* GetTextureView();

private:
	ID3D11ShaderResourceView* m_textureView;
};

