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
