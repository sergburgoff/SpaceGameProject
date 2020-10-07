#pragma once

#include <chrono>

class gameTimer
{
public:
	gameTimer();

	void addSeconds(size_t time);

	//
	// Устанавливается время, за которое нужно пройти уровень
	// Берется из текстового файла
	//
	void setStartTime(size_t time);
	
	//
	// При перезапуске уровня таймер устанавливается вновь в свое изначальное значение
	//
	void ReturnToStartTime();

	//
	// Уменьшение времени на одну секунду
	//
	void Tick();

	size_t getCurrTime();
private:
	std::chrono::time_point<std::chrono::steady_clock> _last_iteration;
	std::chrono::seconds _end;
	std::chrono::seconds _start;
};

