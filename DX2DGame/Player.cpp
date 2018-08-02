#include "Player.h"
#include "Input.h"


Player::Player()
{
}


Player::~Player()
{
}


void Player::Initialize(ID3D11DeviceContext* deviceContext, ID3D11Device* device, 
	float posX, float posY, SPRITE_INFO spriteInfo, float scrWidth, float scrHeight, Input* input)
{
	GameObject::Initialize(deviceContext, device, posX, posY, spriteInfo, scrWidth, scrHeight);
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
}

void Player::MoveLeft()
{
	MessageBox(NULL, L"Left", L"Test", MB_OK);
}

void Player::MoveRight()
{
	MessageBox(NULL, L"Right", L"Test", MB_OK);
}

void Player::MoveDown()
{
	MessageBox(NULL, L"Down", L"Test", MB_OK);
}

void Player::MoveUp()
{
	MessageBox(NULL, L"Up", L"Test", MB_OK);
}