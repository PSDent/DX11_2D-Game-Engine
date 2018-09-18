#pragma once
#include <vector>
#include <map>
#include <string>
#include "Animation.h"
#include "Common.h"
#include "Sprite.h"

class Animator
{
public:
	Animator();
	Animator(Sprite*);
	~Animator();

	void Initialize();
	void AddAnim(Animation);

	void CheckAnimCondition();
	Animation SearchAnim(std::string);

	void SetCondition(std::string, std::string, std::string);

	void Frame();

	void SetTrigger(std::string, bool);
	void SetBool(std::string, bool);
	void PlayAnim(std::string);

private:
	int *tex_X;
	int *tex_Y;

	Animation *m_nowPlayingAnim;
	Sprite *m_mySprite;
	std::map<std::string, Animation> *m_animContainer;
	std::map<std::string, Animation> *m_animCondition_Container;
};