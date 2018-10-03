#include "Player.h"
#include "Input.h"


Player::Player()
{
	m_jumpPower = 3.0f;
}


Player::~Player()
{
}


void Player::Initialize(ID3D11DeviceContext* deviceContext, ID3D11Device* device, 
	float posX, float posY, float scrWidth, float scrHeight, Input* input)
{
	GameObject::Initialize(deviceContext, device, posX, posY, scrWidth, scrHeight);
	SetInput(input);
	SetKeyFunc();
}

void Player::SetInput(Input *input)
{
	m_input = input;
}

void Player::SetKeyFunc()
{
	m_input->SetTargetClass(this);

	m_input->BindingKey("LEFT", &Player::MoveLeft);
	m_input->BindingKey("RIGHT", &Player::MoveRight);
	m_input->BindingKey("DOWN", &Player::MoveDown);
	m_input->BindingKey("UP", &Player::MoveUp);
	m_input->BindingKey("JUMP", &Player::Jump);
}

void Player::MoveLeft()
{
	GameObject::MovePos(-MOVE_SPEED, 0);
	GetComponent<Sprite*>()->SetFlipX(true);
	// MessageBox(NULL, L"Left", L"Test", MB_OK);
}

void Player::MoveRight()
{
	GameObject::MovePos(MOVE_SPEED, 0);
	GetComponent<Sprite*>()->SetFlipX(false);
	//MessageBox(NULL, L"Right", L"Test", MB_OK);
}

void Player::MoveDown()
{
	GameObject::MovePos(0, MOVE_SPEED);
	//MessageBox(NULL, L"Down", L"Test", MB_OK);
}

void Player::MoveUp()
{
	GameObject::MovePos(0, -MOVE_SPEED);
	//MessageBox(NULL, L"Up", L"Test", MB_OK);
}

void Player::Jump()
{
	GameObject::GetComponent<RigidBody2D*>()->AddForce(XMFLOAT2{ 0.0f, m_jumpPower });
}