#pragma once
#include <vector>
#include <map>
#include <string>
#include "Animation.h"
#include "Common.h"

class Animator
{
public:
	Animator();
	~Animator();

	void Initialize();
	void AddAnim(Animation*);

	void CheckAnimCondition();
	Animation* SearchAnim(std::string);

	void SetCondition(std::string, std::string, std::string);

	void SetTrigger(std::string, bool);
	void SetBool(std::string, bool);
	void PlayAnim(std::string);

private:
	Animation *m_nowPlayingAnim;
	std::map<std::string, Animation*> *m_animContainer;
};

