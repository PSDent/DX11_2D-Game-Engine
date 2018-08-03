#include "Animator.h"



Animator::Animator()
{
}


Animator::~Animator()
{
}

void Animator::Initialize()
{

}

void Animator::AddAnim(Animation* anim)
{
	m_animContainer->insert(std::make_pair(anim->GetName(), anim));
} 

void Animator::CheckAnimCondition()
{

}

Animation* Animator::SearchAnim(std::string animName)
{
	return m_animContainer->find(animName)->second;
}

void Animator::SetTrigger(std::string, bool)
{

}

void Animator::SetBool(std::string, bool)
{

}

void Animator::PlayAnim(std::string)
{}
