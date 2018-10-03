#pragma once
#include <Windows.h>
#include <DirectXMath.h>

using namespace DirectX;

class MathLib
{
public:
	MathLib();
	~MathLib();
	static XMFLOAT2 Lerp2D(XMFLOAT2, XMFLOAT2, float);
	static XMFLOAT2 NormalizeVector2(XMFLOAT2);
	static float Vector2Force(XMFLOAT2);
};

