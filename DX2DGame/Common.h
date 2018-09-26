#pragma once

#include <Windows.h>
#include <DirectXMath.h>

using namespace DirectX;

// 스프라이트 경로
static WCHAR *SEAFLOOR = L"seafloor.dds";
static WCHAR *MUSHROOM = L"Mush.png";
static WCHAR *FUMICO = L"Fumiko.png";
static WCHAR *Cat = L"Cat.png";

struct SPRITE_INFO
{
	WCHAR *spritePath;		// Sprite 경로
	float width, height;    // Sprite 가로 세로
};

struct ANIMATION_INFO
{
	WCHAR *spritePath;		// 재생시킬 애니메이션 스프라이트
	float frameWidth;		// 애니메이션 한 프레임의 가로 길이 (전체 1)
	float frameHeight;		// 에니메이션 한 프레임의 세로 길이 (전체 1)
	float row;				// 재생시킬 애니메이션의 세로 개수
	float column;			// 재생시킬 애니메이션의 가로 개수
	float speed;			// 한 프레임당 시간(s)
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
