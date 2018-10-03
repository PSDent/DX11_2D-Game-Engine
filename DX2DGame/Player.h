#pragma once
#include "GameObject.h"

const float MOVE_SPEED = 1.0f;

class Input;

class Player : public GameObject
{
public:
	Player();
	~Player();

	void Initialize(ID3D11DeviceContext*, ID3D11Device*, float, float, float, float, Input*);
	void SetInput(Input*);
	
private:
	void SetKeyFunc();

	void MoveLeft();
	void MoveRight();
	void MoveUp();
	void MoveDown();
	void Jump();

private:
	Input *m_input;

	float m_jumpPower;

};

