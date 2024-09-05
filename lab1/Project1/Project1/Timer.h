#pragma once

class Timer {

	bool hasTimerStarted;

public:

	float currentTime;

	void ResetTimer();

	void StartTimer();

	void TimerHandler();
};



