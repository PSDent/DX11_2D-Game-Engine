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
	m_keyArr = new PLAYER_FUNC[m_SIZE];
	for (int i = 0; i < m_SIZE; ++i)
		m_dictionary[keyStr[i]] = (Key)i;
}

void Input::BindingKey(std::string key, PLAYER_FUNC fp)
{
	Input::Key key_enum;
	key_enum = ConvertEnum(key);
	m_keyArr[key_enum] = fp;
}

void Input::CallKeyFunc(std::string str)
{
	Input::Key key_enum = ConvertEnum(str);
	(m_player->*m_keyArr[key_enum])();
}

Input::Key Input::ConvertEnum(std::string str)
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