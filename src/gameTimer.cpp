#include "stdafx.h"
#include "gameTimer.h"

gameTimer::gameTimer()
	: _end(0)
{}

void gameTimer::Tick()
{
	//
	// ≈сли с момента последней итерации прошла секунда, то таймер уменьшаетс€
	//
	if (_last_iteration + std::chrono::seconds(1) <= 
		std::chrono::high_resolution_clock::now())
	{
		if (_end.count() != 0)
		{
			--_end;
			_last_iteration = std::chrono::high_resolution_clock::now();
		}
	}
}

void gameTimer::addSeconds(size_t time)
{
	_end = std::chrono::seconds(time);
}

void gameTimer::setStartTime(size_t time)
{
	_start = std::chrono::seconds(time);
}

void gameTimer::ReturnToStartTime()
{
	_end = _start;
}

size_t gameTimer::getCurrTime()
{
	return (size_t)_end.count();
}
