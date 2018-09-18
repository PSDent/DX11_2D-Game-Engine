#include "Animator.h"


// Sprite 객체의 TexX, TexY, TexWidth, TexHeight를 조작하여
// 애니메이션을 구동시키게 할 것.

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

// 애니메이션 클래스 안에서든, 애니메이터 클래스에서던
// 여러 조건을 검사해서 조건에 맞으면 애니메이션을 플레이하는
// 기능을 구현할 것. 

// 또한 트리거나 불 변수를 설정 할 수 있도록 할 것.



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
