#pragma once
#include <string>
#include "Common.h"
#include "Sprite.h"

class Animation
{
public:
	Animation();
	~Animation();
	void Initialize(std::string, ANIMATION_INFO);

	void Play();
	std::string GetName();

private:
	Sprite *m_sprite;
	ANIMATION_INFO m_animInfo;
	std::string m_animName;
};

