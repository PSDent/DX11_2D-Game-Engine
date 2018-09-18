#pragma once
#include <iostream>
#include <map>
#include <Windows.h>

class Timer
{
public:
	Timer();
	~Timer();

	void Initialize();
	void Frame();
	bool WaitForSec(float, int, bool);
	float GetTime();
	int GetEmptySlot();

private:
	void AddFrameTime();
	bool CheckTime(int);
	bool SearchTimer(int);
	void SetTimer(float, int);//이 함수들을 Waiter 클래스에 구현할 것

private:
	INT64 m_frequency;
	float m_ticksPerMs;
	INT64 m_startTime;
	float m_frameTime;

	// 1 - 현재 누적 시간, 2 - 목표 시간
	std::map<int, float> *m_timeStoragy;
};

