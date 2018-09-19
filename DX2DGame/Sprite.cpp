#include "Sprite.h"

Sprite::Sprite(float &X, float &Y) : m_objPosX(X), m_objPosY(Y)
{
	m_texture = NULL;
	m_spriteInfo = NULL;
	m_indexBuffer = NULL;
	m_vertexBuffer = NULL;
	m_animInfo = NULL;

	m_height = 100;
	m_width = 100;

	m_TexWidth = 0.3f;
	m_TexHeight = 0.25f;
	m_TexPosX = 0;
	m_TexPosY = 0;
}

Sprite::~Sprite()
{

}

//Sprite::Sprite(const Sprite& sprite)
//{
//}

void Sprite::ChangeTexCoord(int x, int y)
{

}

ID3D11ShaderResourceView* Sprite::GetTextureView()
{
	return m_texture->GetTextureView();
}

Texture* Sprite::GetTexture()
{
	return m_texture;
}

bool Sprite::Initialize(ID3D11Device* device, ID3D11DeviceContext* deviceContext, SPRITE_INFO spriteInfo, float width, float height)
{
	// 스프라이트 정보를 저장
	SetSpriteInfo(spriteInfo);
	// 윈도우 크기 저장
	SetScreenInfo(width, height);
	
	SetSpritePos();

	// 텍스처 적재 
	LoadTexture(device, m_spriteInfo->spritePath);

	InitializeBuffer(device, deviceContext);

	return true;
}

void Sprite::LoadTexture(ID3D11Device* device, WCHAR* texPath)
{
	if (m_texture != NULL)
	{
		m_texture->Release();
		delete m_texture;
	}
	m_texture = new Texture();

	m_texture->SetTexture(device, texPath);

	return;
}

void Sprite::InitializeBuffer(ID3D11Device* device, ID3D11DeviceContext* deviceContext)
{
	HRESULT hr;
	D3D11_BUFFER_DESC bd;

	float left, right, top, bottom;
	// Calculate the screen coordinates of the left side of the bitmap.
	left = (float)((m_scrWidth / 2) * -1) + (float)m_PosX;

	// Calculate the screen coordinates of the right side of the bitmap.
	right = left + (float)m_spriteInfo->width;

	// Calculate the screen coordinates of the top of the bitmap.
	top = (float)(m_scrHeight / 2) - (float)m_PosY;

	// Calculate the screen coordinates of the bottom of the bitmap.
	bottom = top - (float)m_spriteInfo->height;

	//SimpleVertex *vertices = new SimpleVertex[4];
	SimpleVertex vertices[] = 
	{
		{XMFLOAT3(left, bottom, 0.0f), XMFLOAT2(0.0f, 1.0f) },
		{ XMFLOAT3(left, top, 0.0f), XMFLOAT2(0.0f, 0.0f) },
		{ XMFLOAT3(right, top, 0.0f), XMFLOAT2(1.0f, 0.0f) },
		{ XMFLOAT3(right, bottom, 0.0f), XMFLOAT2(1.0f, 1.0f) }
	};

	// VertexBuffer
	ZeroMemory(&bd, sizeof(bd));
	bd.Usage = D3D11_USAGE_DYNAMIC;
	bd.ByteWidth = sizeof(SimpleVertex) * 4;
	bd.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;
	bd.BindFlags = D3D11_BIND_VERTEX_BUFFER;

	D3D11_SUBRESOURCE_DATA initData;
	ZeroMemory(&initData, sizeof(initData));
	initData.pSysMem = vertices;
	hr = device->CreateBuffer(&bd, &initData, &m_vertexBuffer);
	if (FAILED(hr))
	{
		MessageBox(NULL, L"Failed to Create VertexBuffer", L"Error", MB_OK);
		return;
	}

	// IndexBuffer
	UINT indices[] = 
	{
		0, 1, 2,
		2, 3, 0
	};

	m_index = sizeof(indices) / sizeof(UINT);

	bd.Usage = D3D11_USAGE_DEFAULT;
	bd.ByteWidth = sizeof(UINT) * 6;
	bd.BindFlags = D3D11_BIND_INDEX_BUFFER;
	bd.CPUAccessFlags = 0;
	initData.pSysMem = indices;
	hr = device->CreateBuffer(&bd, &initData, &m_indexBuffer);
	if (FAILED(hr))
	{
		MessageBox(NULL, L"Failed to Create IndexBuffer", L"Error", MB_OK);
		return;
	}
}

void Sprite::SetSpritePos()
{
	m_PosX = m_objPosX;
	m_PosY = m_objPosY;
}

void Sprite::SetScreenInfo(float width, float height)
{
	m_scrWidth = width;
	m_scrHeight = height;
}

void Sprite::SetSpriteInfo(SPRITE_INFO spriteInfo)
{
	m_spriteInfo = new SPRITE_INFO();
	m_spriteInfo->width = spriteInfo.width;
	m_spriteInfo->height = spriteInfo.height;
	m_spriteInfo->spritePath = spriteInfo.spritePath;

	m_TexWidth = m_spriteInfo->width;
	m_TexHeight = m_spriteInfo->height;
}

void Sprite::Render(ID3D11DeviceContext* deviceContext)
{
	UINT stride = sizeof(SimpleVertex);
	UINT offset = 0;
	
	UpdateBuffer(deviceContext);

	deviceContext->IASetVertexBuffers(0, 1, &m_vertexBuffer, &stride, &offset);

	deviceContext->IASetIndexBuffer(m_indexBuffer, DXGI_FORMAT_R32_UINT, 0);

	deviceContext->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
}

void Sprite::UpdateBuffer(ID3D11DeviceContext* deviceContext)
{
	D3D11_MAPPED_SUBRESOURCE mappedResource;
	SimpleVertex* verticesPtr;

	float left, right, top, bottom;
	// Calculate the screen coordinates of the left side of the bitmap.
	left = (float)((m_scrWidth / 2) * -1) + (float)m_objPosX;

	// Calculate the screen coordinates of the right side of the bitmap.
	right = left + m_width;//(float)m_spriteInfo->width;

	// Calculate the screen coordinates of the top of the bitmap.
	top = (float)(m_scrHeight / 2) - (float)m_objPosY;

	// Calculate the screen coordinates of the bottom of the bitmap.
	bottom = top - m_height;//(float)m_spriteInfo->height;
		
	if (m_animInfo)
	{
		m_TexPosX += 1;
		if (m_TexPosX > m_animInfo->column)
		{
			m_TexPosY += 1;
			m_TexPosX = 0;
			if (m_TexPosY > m_animInfo->row)
			{
				m_TexPosY = 0;
				m_TexPosX = 0;
			}
		}
	}
	
	SimpleVertex vertices[] =
	{
		{ XMFLOAT3(left, bottom, 0.0f), XMFLOAT2(m_TexPosX * m_TexWidth, (m_TexPosY + 1) * m_TexHeight) },
		{ XMFLOAT3(left, top, 0.0f), XMFLOAT2(m_TexPosX * m_TexWidth, m_TexPosY * m_TexHeight) },
		{ XMFLOAT3(right, top, 0.0f), XMFLOAT2((m_TexPosX + 1) * m_TexWidth, m_TexPosY * m_TexHeight) },
		{ XMFLOAT3(right, bottom, 0.0f), XMFLOAT2((m_TexPosX + 1) * m_TexWidth, (m_TexPosY + 1) * m_TexHeight) }
	};

	deviceContext->Map(m_vertexBuffer, 0, D3D11_MAP_WRITE_DISCARD, 0, &mappedResource);
	verticesPtr = (SimpleVertex*)mappedResource.pData;
	memcpy(verticesPtr, (void*)vertices, (sizeof(SimpleVertex) * 8));
	deviceContext->Unmap(m_vertexBuffer, 0);
}

void Sprite::AnimationSet(Animation anim)
{
	ANIMATION_INFO animInfo = anim.GetAnimInfo();

	m_animInfo = new ANIMATION_INFO;

	m_animInfo->spritePath = animInfo.spritePath;
	m_animInfo->frameWidth = animInfo.frameWidth;
	m_animInfo->frameHeight = animInfo.frameHeight;
	m_animInfo->row = animInfo.row;
	m_animInfo->column = animInfo.column;
	m_animInfo->speed = animInfo.speed;

	m_TexWidth = m_animInfo->frameWidth;
	m_TexHeight = m_animInfo->frameHeight;
}

int Sprite::GetIndex()
{
	return m_index;
}