#pragma once

#include <chrono>

class gameTimer
{
public:
	gameTimer();

	void addSeconds(size_t _time);
	void Tick();
	size_t getCurrTime();
private:
	std::chrono::time_point<std::chrono::steady_clock> last_iteration;
	std::chrono::seconds end;
};

