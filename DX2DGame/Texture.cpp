#include "Texture.h"

Texture::Texture()
{
	m_textureView = NULL;
}


Texture::~Texture()
{
}

void Texture::Release()
{
	if (m_textureView)
	{
		m_textureView->Release();
		delete m_textureView;
	}
}

ID3D11ShaderResourceView* Texture::GetTextureView()
{
	return m_textureView;
}

bool Texture::SetTexture(ID3D11Device* device, WCHAR* texPath)
{
	HRESULT hr;

	hr = D3DX11CreateShaderResourceViewFromFile(device, texPath, NULL, NULL, &m_textureView, NULL);
	if (FAILED(hr))
	{
		MessageBox(NULL, L"Failed to Create Texture Resource. ", L"Error", MB_OK);
		return false;
	}

	return true;
}