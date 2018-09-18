#pragma once
#include <string>
#include "Common.h"
//#include "Sprite.h"

class Animation
{
public:
	Animation();
	Animation(std::string, ANIMATION_INFO);
	~Animation();

	void Play();
	std::string GetName();

	ANIMATION_INFO GetAnimInfo();

private:
	//Sprite *m_sprite;
	ANIMATION_INFO m_animInfo;
	std::string m_animName;
	bool *m_condition;
};

