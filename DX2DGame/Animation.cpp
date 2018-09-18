#include "Animation.h"



Animation::Animation()
{
	m_condition = NULL;
}

Animation::Animation(std::string name, ANIMATION_INFO animInfo)
{
	m_animName = name;
	m_animInfo = animInfo;
}


Animation::~Animation()
{
}

void Animation::Play()
{

}

std::string Animation::GetName()
{
	return m_animName;
}

ANIMATION_INFO Animation::GetAnimInfo()
{
	return m_animInfo;
}