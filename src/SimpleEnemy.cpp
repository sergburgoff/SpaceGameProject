#include "stdafx.h"
#include <random>
#include <time.h>
#include <chrono>
#include <thread>
#include "SimpleEnemy.h"
#include "Settings.h"

SimpleEnemy::SimpleEnemy() : MovableTarget("SimpleEnemy")
{
	_collisionObj_shield = 0;
	_collisionWall_shield = 0;

	_speed = Settings::SIMPLE_ENEMIES_SPEED; // 5.0f;
	_hitPoints = 1;

	x = Random((float)Settings::LEFT_BORDER + SIZE_COEF, (float)(Settings::RIGHT_BORDER - 100));
	std::this_thread::sleep_for(std::chrono::seconds(1));
	y = Random((float)Settings::BOTTOM_BORDER + 150 + SIZE_COEF, (float)(Settings::TOP_BORDER - 100));

	std::this_thread::sleep_for(std::chrono::seconds(1));

	setDirection();
}

bool SimpleEnemy::CheckWallCollision()
{
	return x + width > Settings::RIGHT_BORDER ||
		y + height > Settings::TOP_BORDER ||
		y < Settings::BOTTOM_BORDER + 150 || x < Settings::LEFT_BORDER;
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
	float y_pos = y + _speed * math::sin(_angle * (math::PI / 180));
	float x_pos = x + _speed * math::cos(_angle * (math::PI / 180));

	if (y_pos > Settings::BOTTOM_BORDER + 150 - SIZE_COEF &&
		y_pos + height < Settings::TOP_BORDER + SIZE_COEF &&
		x_pos + width < Settings::RIGHT_BORDER + SIZE_COEF &&
		x_pos > Settings::LEFT_BORDER - SIZE_COEF)
	{
		y = y_pos;
		x = x_pos;
	}
}

void SimpleEnemy::onCollision()
{
	MM::manager.PlaySample("CollisionSound");

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


void SimpleEnemy::Hit()
{
	if (_hitPoints != 0)
		--_hitPoints;
}

size_t SimpleEnemy::getCurrentHitPoints()
{
	return _hitPoints;
}

void SimpleEnemy::chargeObjectShield()
{
	_collisionObj_shield = 5;
}

void SimpleEnemy::chargeWallShield()
{
	_collisionWall_shield = 10;
}

void SimpleEnemy::decreaseShield()
{
	if (_collisionObj_shield != 0)
		--_collisionObj_shield;

	if (_collisionWall_shield != 0)
		--_collisionWall_shield;

}

bool SimpleEnemy::isObjectShieldOn()
{
	return _collisionObj_shield != 0;
}

bool SimpleEnemy::isWallShieldOn()
{
	return _collisionWall_shield != 0;
}