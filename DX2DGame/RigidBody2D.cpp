#include "RigidBody2D.h"

RigidBody2D::RigidBody2D(float &x, float &y) : m_posX(x), m_posY(y)
{
	m_isGrounded = false;
	m_isAddedForce = false;
	m_gravity = 1.0f;
	m_timeSum = 0.0f;
	m_accelGravity = 0.0f;
}

RigidBody2D::~RigidBody2D()
{
}

void RigidBody2D::AddForce(XMFLOAT2 direction)
{
	m_force = direction;
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
		if (m_timeSum >= 100)
		{
			
			//MessageBox(NULL, L"asd", L"asd", MB_OK);
			
		}
		//m_accelGravity = m_timeSum ;
		//m_posY += m_timeSum;
		m_posY += deltaTime;
	}
}

void RigidBody2D::ApplyForce(float deltaTime)
{
	if (m_isAddedForce)
	{
		m_posX += m_force.x;
		m_posY += m_force.y;
	}

}

void RigidBody2D::Frame(float deltaTime)
{
	ApplyForce(deltaTime);
	ApplyGravity(deltaTime);
}