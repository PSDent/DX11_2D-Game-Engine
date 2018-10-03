#pragma once
#include <DirectXMath.h>
#include <Windows.h>
#include <cmath>

#include "MathLib.h"

using namespace DirectX;

class RigidBody2D
{
public:
	RigidBody2D();
	RigidBody2D(float&, float&);	
	~RigidBody2D();

	void AddForce(XMFLOAT2);
	void SetGravity(float);
	void Frame(float);

private:
	void ApplyForce(float);
	void ApplyGravity(float);

private:
	XMFLOAT2 m_fromPos;
	XMFLOAT2 m_toPos;
	float m_posPercent;

	float m_force;
	XMFLOAT2 m_normal;

	float m_forceTimeSum;
	float &m_posX, &m_posY;
	float m_gravity;
	float m_timeSum;
	float m_accelGravity;
	float m_mass;

	bool m_resistance;
	bool m_isGrounded;
	bool m_isAddedForce;

};

