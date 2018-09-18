#include "Timer.h"
#include <Windows.h>

Timer::Timer()
{
}


Timer::~Timer()
{
}

void Timer::Initialize()
{
	QueryPerformanceFrequency((LARGE_INTEGER*)&m_frequency);
	if (m_frequency == 0)
		return;

	m_ticksPerMs = (float)(m_frequency / 1000);

	QueryPerformanceCounter((LARGE_INTEGER*)&m_startTime);

	m_timeStoragy = new std::map<int, float>();
}

void Timer::Frame()
{
	INT64 currentTime;
	float timeDiffrence;

	QueryPerformanceCounter((LARGE_INTEGER*)&currentTime);

	timeDiffrence = (float)(currentTime - m_startTime);
	
	m_frameTime = timeDiffrence / m_ticksPerMs;
	
	m_startTime = currentTime;

	AddFrameTime();
}

void Timer::AddFrameTime()
{
	std::map<int, float>::iterator iter = m_timeStoragy->begin();

	for (; iter != m_timeStoragy->end(); ++iter)
		iter->second -= m_frameTime;

	return;
}

float Timer::GetTime()
{
	return m_frameTime;
}

bool Timer::SearchTimer(int timerNum)
{
	std::map<std::string, float>::iterator iter;
	// iter = m_timeStoragy->find(timerNum);

	//if(*iter != NULL	)
	return true;
}

bool Timer::CheckTime(int timerNum)
{
	return true;
}

int Timer::GetEmptySlot()
{
	for (int i = 0; ; i++)
	{
		if (SearchTimer(i) == false)
			return i;
	}
}

bool Timer::WaitForSec(float sec, int timeNum, bool isBegin)
{
	return true;
}