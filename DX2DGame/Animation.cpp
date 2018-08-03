#include "Animation.h"



Animation::Animation()
{
}


Animation::~Animation()
{
}

void Animation::Initialize(std::string name, ANIMATION_INFO animInfo)
{
	// 여기 m_sprite 변수를 할당, 초기화 할 것.
	m_animName = name;
	m_animInfo = animInfo;
}

void Animation::Play()
{

}

std::string Animation::GetName()
{
	return m_animName;
}