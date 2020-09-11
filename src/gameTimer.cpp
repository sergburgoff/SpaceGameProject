#include "stdafx.h"
#include "gameTimer.h"

gameTimer::gameTimer()
	: end(0)
{}

void gameTimer::Tick()
{
	if (last_iteration + std::chrono::seconds(1) <= 
		std::chrono::high_resolution_clock::now())
	{
		if (end.count() != 0)
		{
			--end;
			last_iteration = std::chrono::high_resolution_clock::now();
		}
	}
}

void gameTimer::addSeconds(size_t _time)
{
	end = std::chrono::seconds(_time);
}

size_t gameTimer::getCurrTime()
{
	return (size_t)end.count();
}
