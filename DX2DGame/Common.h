#pragma once

#include <Windows.h>
#include <DirectXMath.h>

using namespace DirectX;

static WCHAR *SEAFLOOR = L"seafloor.dds";

struct SPRITE_INFO
{
	WCHAR *spritePath;
	float width, height;
};

struct ANIMATION_INFO
{
	WCHAR *spritePath;
	float frameWidth;
	float frameHeight;
	float row;
	float column;
	float speed;
};

struct SimpleVertex
{
	XMFLOAT3 Pos;
	XMFLOAT2 Tex;
};

struct CBNeverChanges
{
	XMMATRIX mView;
};

struct CBChangeOnResize
{
	XMMATRIX mProjection;
};

struct CBChangesEveryFrame
{
	XMMATRIX mWorld;
	XMFLOAT4 vMeshColor;
};
