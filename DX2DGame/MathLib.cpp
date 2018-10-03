#include "MathLib.h"

MathLib::MathLib()
{
}


MathLib::~MathLib()
{
}

XMFLOAT2 MathLib::Lerp2D(XMFLOAT2 from, XMFLOAT2 to, float betVal)
{
	XMFLOAT2 resultV;

	resultV.x = from.x * (1.0 - betVal) + to.x * betVal;
	resultV.y = from.y * (1.0 - betVal) + to.y * betVal;

	return resultV;
}

XMFLOAT2 MathLib::NormalizeVector2(XMFLOAT2 vector)
{
	float size = sqrt((vector.x * vector.x) + (vector.y * vector.y));
	XMFLOAT2 newVector{ vector.x / size, vector.y / size };

	return newVector;
}

float MathLib::Vector2Force(XMFLOAT2 vector)
{
	float force = sqrt((vector.x * vector.x) + (vector.y * vector.y));
	return force;
}