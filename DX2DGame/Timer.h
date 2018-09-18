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
	void SetTimer(float, int);//�� �Լ����� Waiter Ŭ������ ������ ��

private:
	INT64 m_frequency;
	float m_ticksPerMs;
	INT64 m_startTime;
	float m_frameTime;

	// 1 - ���� ���� �ð�, 2 - ��ǥ �ð�
	std::map<int, float> *m_timeStoragy;
};

