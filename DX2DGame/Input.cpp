#include "Input.h"
#include "Player.h"

Input::Input()
{
}


Input::~Input()
{
}

void Input::Initialize()
{
	m_keyArr = new PLAYER_FUNC[(int)Key::SIZE];
	//m_keyState = new bool[(int)Key::SIZE];
	m_keyState = new bool[4];
	for (int i = 0; i < (int)Key::SIZE; ++i)
	{
		m_keyState[i] = false;
		m_dictionary[keyStr[i]] = (Key)i;
	}
}

void Input::BindingKey(std::string key, PLAYER_FUNC fp)
{
	Key key_enum;
	key_enum = ConvertEnum(key);
	m_keyArr[(int)key_enum] = fp;
}

void Input::CallKeyFunc(std::string str)
{
	Key key_enum = ConvertEnum(str);
	(m_player->*m_keyArr[(int)key_enum])();
}

Key Input::ConvertEnum(std::string str)
{
	std::map<std::string, Key>::iterator iter = m_dictionary.find(str);

	if (iter != m_dictionary.end())
		return iter->second;
	else
		return static_cast<Key>(-1);
}

void Input::SetTargetClass(Player *player)
{
	m_player = player;
}

bool Input::IsKeyDown(std::string key)
{
	return m_keyState[(int)ConvertEnum(key)];
}

void Input::InputKey(std::string key, bool val)
{
	m_keyState[(int)ConvertEnum(key)] = val;
}

void Input::ProcessInput()
{
	for (int i = 0; i < (int)Key::SIZE; ++i)
	{
		if (m_keyState[i])
			CallKeyFunc(keyStr[i]);
	}
}