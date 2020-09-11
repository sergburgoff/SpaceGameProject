#pragma once

#include <chrono>

class gameTimer
{
public:
	gameTimer(size_t _time);

	void addTime();
	void Tick();
	size_t getCurrTime();
private:
	std::chrono::time_point<std::chrono::steady_clock> last_iteration;
	std::chrono::seconds end;
};

