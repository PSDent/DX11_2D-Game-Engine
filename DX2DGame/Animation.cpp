#include "Animation.h"



Animation::Animation()
{
}


Animation::~Animation()
{
}

void Animation::Initialize(std::string name, ANIMATION_INFO animInfo)
{
	// ���� m_sprite ������ �Ҵ�, �ʱ�ȭ �� ��.
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