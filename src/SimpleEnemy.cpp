#include "stdafx.h"
#include <random>
#include <time.h>
#include <chrono>
#include <thread>
#include "SimpleEnemy.h"

enum { // ”¡–¿“‹!
	WINDOW_WIDTH = 1000,
	WINDOW_HEIGHT = 760
};

#define SIZE_COEF 15.f

enum { // ”¡–¿“‹!
	BOTTOM_BORDER = 60,
	TOP_BORDER = 755,
	RIGHT_BORDER = 1000,
	LEFT_BORDER = -10
};

SimpleEnemy::SimpleEnemy() : MovableTarget("SimpleEnemy")
{
	collisionObj_shield = 0;
	collisionWall_shield = 0;
	speed = 5.0f;
	Scale(70.0f, 70.0f);
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

void SimpleEnemy::Move()
{
	float y_pos = y + speed * math::sin(_angle * (math::PI / 180));
	float x_pos = x + speed * math::cos(_angle * (math::PI / 180));
	if (y_pos > BOTTOM_BORDER - SIZE_COEF &&
		y_pos + height < TOP_BORDER + SIZE_COEF &&
		x_pos + width < RIGHT_BORDER + SIZE_COEF &&
		x_pos > LEFT_BORDER - SIZE_COEF)
	{
		y = y_pos;
		x = x_pos;
	}
}

void SimpleEnemy::onCollision()
{
	if (_angle  > 180.0f)
	{
		_angle = _angle - 180.0f;
	}
	else
		_angle += 180.0f;
}

void SimpleEnemy::setDirection()
{
	_angle = Random(0.0f, 360.0f);
}

void SimpleEnemy::Destroy()
{
	DeathAnimation();
}

void SimpleEnemy::DeathAnimation()
{

}