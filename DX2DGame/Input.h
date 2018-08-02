#pragma once
#include <string>
#include <iterator>
#include <map>

class __single_inheritance Player;

typedef void(Player::*PLAYER_FUNC)();
static std::string keyStr[] = { "LEFT", "RIGHT", "UP", "DOWN" };

class Input
{
public:
	enum Key
	{
		LEFT,
		RIGHT,
		UP,
		DOWN
	};

	Input();
	~Input();

	void Initialize();
	void BindingKey( std::string, PLAYER_FUNC);
	void CallKeyFunc(std::string);
	void SetTargetClass(Player*);

	void Release();
private:
	Key ConvertEnum(std::string);

private:
	const int m_SIZE = 4;

	std::map<std::string, Key> m_dictionary;
	Player *m_player;
	PLAYER_FUNC *m_keyArr;
};