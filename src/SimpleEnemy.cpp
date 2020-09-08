#include "stdafx.h"
#include <random>
#include <time.h>
#include <chrono>
#include <thread>
#include "SimpleEnemy.h"

enum { // ”¡–¿“‹!
	WINDOW_WIDTH = 1024,
	WINDOW_HEIGHT = 768
};

SimpleEnemy::SimpleEnemy() : MovableTarget("SimpleEnemy")
{
	speed = 1.0f;
	Scale(100.0f, 100.0f);
	x = Random(1.0f, (float)WINDOW_WIDTH);
	std::this_thread::sleep_for(std::chrono::seconds(1));
	y = Random(1.0f, (float)WINDOW_HEIGHT);
	std::this_thread::sleep_for(std::chrono::seconds(1));
	setDirection();
}

inline int SimpleEnemy::Random(int min, int max)
{
	srand(std::time(NULL) * 3);
	std::mt19937 gen(std::time(NULL) + rand());
	std::uniform_int_distribution<int> dis(min, max);
	return dis(gen);
}

inline float SimpleEnemy::Random(float min, float max)
{
	srand(std::time(NULL) * 3);
	std::mt19937 gen(std::time(NULL) + rand());
	std::uniform_real_distribution<float> dis(min, max);
	return dis(gen);
}

void SimpleEnemy::onCollision()
{
	if (_angle + 180.0f > 360.0f)
	{
		_angle += 180.0f - (360.0f - _angle);
	}
	else
		_angle += 180.0f;
}

void SimpleEnemy::setDirection()
{
	/*float point_x, point_y;
	
	switch (Random(1, 4))
	{
	case 1:
		point_x = 0;
		point_y = Random(1.0f, (float)WINDOW_HEIGHT);
		break;
	case 2:
		point_x = Random(1.0f, (float)WINDOW_WIDTH);
		point_y = (float)WINDOW_HEIGHT;
		break;
	case 3:
		point_x = (float)WINDOW_WIDTH;
		point_y = Random(1.0f, (float)WINDOW_HEIGHT);
		break;
	case 4:
		point_x = Random(1.0f, (float)WINDOW_WIDTH);
		point_y = 0;
		break;
	}
	_angle = (180 / math::PI) * -math::atan(point_y - y,
		point_x - x);*/

	_angle = Random(0.0f, 360.0f);
}

void SimpleEnemy::Destroy()
{
	DeathAnimation();
}

void SimpleEnemy::DeathAnimation()
{

}