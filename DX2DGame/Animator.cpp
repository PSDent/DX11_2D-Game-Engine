#include "Animator.h"


// Sprite ��ü�� TexX, TexY, TexWidth, TexHeight�� �����Ͽ�
// �ִϸ��̼��� ������Ű�� �� ��.

Animator::Animator()
{
	m_nowPlayingAnim = NULL;
	m_animContainer = new std::map<std::string, Animation>();
	m_animCondition_Container = NULL;
}

Animator::Animator(Sprite *sprite)
{
	m_mySprite = sprite;
	m_nowPlayingAnim = NULL;
	m_animContainer = new std::map<std::string, Animation>();
	m_animCondition_Container = NULL;
}

Animator::~Animator()
{
}

void Animator::Initialize()
{

}

void Animator::AddAnim(Animation anim)
{
	m_animContainer->insert(std::make_pair(anim.GetName(), anim));
	m_mySprite->AnimationSet(anim);
} 

void Animator::CheckAnimCondition()
{

}

Animation Animator::SearchAnim(std::string animName)
{
	return m_animContainer->find(animName)->second;
}

// �ִϸ��̼� Ŭ���� �ȿ�����, �ִϸ����� Ŭ����������
// ���� ������ �˻��ؼ� ���ǿ� ������ �ִϸ��̼��� �÷����ϴ�
// ����� ������ ��. 

// ���� Ʈ���ų� �� ������ ���� �� �� �ֵ��� �� ��.



void Animator::Frame()
{

}

void Animator::SetTrigger(std::string, bool)
{

}

void Animator::SetBool(std::string , bool)
{

}

void Animator::PlayAnim(std::string animName)
{
	Animation nowAnim = SearchAnim(animName);
	m_mySprite->AnimationSet(nowAnim);
}
