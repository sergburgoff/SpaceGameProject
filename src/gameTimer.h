#pragma once

#include <chrono>

class gameTimer
{
public:
	gameTimer();

	void addSeconds(size_t time);

	void setStartTime(size_t time);
	
	void ReturnToStartTime();
	void Tick();
	size_t getCurrTime();
private:
	std::chrono::time_point<std::chrono::steady_clock> _last_iteration;
	std::chrono::seconds _end;
	std::chrono::seconds _start;
};

