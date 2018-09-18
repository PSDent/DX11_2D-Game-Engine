#pragma once
#include "Timer.h"
#include <map>

using TStoragy = std::map<int, float>;

class Waiter
{
public:
	Waiter();
	Waiter(Timer *timer, float time);
	~Waiter();

private:
	Timer *m_timer;
	TStoragy *m_timeStoragy;
};