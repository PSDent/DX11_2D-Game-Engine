#include "Waiter.h"



Waiter::Waiter()
{
}


Waiter::~Waiter()
{
}

Waiter::Waiter(Timer *timer, float time)
{
	m_timer = timer;
}