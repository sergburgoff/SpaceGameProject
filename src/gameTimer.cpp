#include "stdafx.h"
#include "gameTimer.h"

gameTimer::gameTimer()
	: _end(0)
{}

void gameTimer::Tick()
{
	if (_last_iteration + std::chrono::seconds(1) <= 
		std::chrono::high_resolution_clock::now())
	{
		if (_end.count() != 0)
		{
			--end;
			_last_iteration = std::chrono::high_resolution_clock::now();
		}
	}
}

void gameTimer::addSeconds(size_t _time)
{
	_end = std::chrono::seconds(_time);
}

size_t gameTimer::getCurrTime()
{
	return (size_t)_end.count();
}
