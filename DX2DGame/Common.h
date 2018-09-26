#pragma once

#include <Windows.h>
#include <DirectXMath.h>

using namespace DirectX;

// ��������Ʈ ���
static WCHAR *SEAFLOOR = L"seafloor.dds";
static WCHAR *MUSHROOM = L"Mush.png";
static WCHAR *FUMICO = L"Fumiko.png";
static WCHAR *Cat = L"Cat.png";

struct SPRITE_INFO
{
	WCHAR *spritePath;		// Sprite ���
	float width, height;    // Sprite ���� ����
};

struct ANIMATION_INFO
{
	WCHAR *spritePath;		// �����ų �ִϸ��̼� ��������Ʈ
	float frameWidth;		// �ִϸ��̼� �� �������� ���� ���� (��ü 1)
	float frameHeight;		// ���ϸ��̼� �� �������� ���� ���� (��ü 1)
	float row;				// �����ų �ִϸ��̼��� ���� ����
	float column;			// �����ų �ִϸ��̼��� ���� ����
	float speed;			// �� �����Ӵ� �ð�(s)
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
