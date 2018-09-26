#pragma once
#include <string>
#include <iterator>
#include <map>
#include "Key.h"

class __single_inheritance Player;

typedef void(Player::*PLAYER_FUNC)();
static std::string keyStr[] = { "LEFT", "RIGHT", "UP", "DOWN" };

class Input
{
public:

	Input();
	~Input();

	void Initialize();
	void BindingKey( std::string, PLAYER_FUNC);
	void CallKeyFunc(std::string);
	void SetTargetClass(Player*);
	bool IsKeyDown(std::string);
	void InputKey(std::string, bool);
	void ProcessInput();

	void Release();
private:
	Key ConvertEnum(std::string);

private:
	//const int m_SIZE = 4;
	bool *m_keyState;
	std::map<std::string, Key> m_dictionary;
	Player *m_player;
	PLAYER_FUNC *m_keyArr;
};