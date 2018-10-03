#include "RigidBody2D.h"

RigidBody2D::RigidBody2D(float &x, float &y) : m_posX(x), m_posY(y)
{
	m_isGrounded = false;
	m_isAddedForce = false;
	m_gravity = 1.0f;
	m_timeSum = 0.0f;
	m_accelGravity = 0.0f;
	m_resistance = 1.0f;
	m_forceTimeSum = 0.0f;
}

RigidBody2D::~RigidBody2D()
{
}

void RigidBody2D::AddForce(XMFLOAT2 direction)
{
	m_force = MathLib::Vector2Force(direction);
	m_normal = MathLib::NormalizeVector2(direction);
	m_forceTimeSum = 0.0f;
	m_timeSum = 0;

	m_isAddedForce = true;
}

void RigidBody2D::SetGravity(float gravity)
{
	m_gravity = gravity;
}

void RigidBody2D::ApplyGravity(float deltaTime)
{
	if (!m_isGrounded)
	{
		m_timeSum += deltaTime;
		
		m_posY += (m_timeSum * 0.001f) * (m_timeSum * 0.001f) * 5.0f * m_gravity;
	}
}

void RigidBody2D::ApplyForce(float deltaTime)
{
	if (m_isAddedForce)
	{
		m_forceTimeSum += deltaTime * 0.001f;

		m_posX += m_normal.x * m_force;
		m_posY -= m_normal.y * m_force;

		m_force -= m_resistance * m_forceTimeSum;
		if (m_force < 0)
			m_isAddedForce = false;
	}
}

void RigidBody2D::Frame(float deltaTime)
{
	ApplyForce(deltaTime);
	ApplyGravity(deltaTime);
}
