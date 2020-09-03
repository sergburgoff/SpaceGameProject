#include "stdafx.h"
#include "SimpleEnemy.h"

bool SimpleEnemy::CheckCollision(GameObject &other)
{
	if (this->x < other.x + other.width &&
		this->x + this->width > other.x &&
		this->y < other.y + other.hight &&
		this->y + this->hight > other.y)
	{
		/*if (other.type == "Bullet")
			DeathAnimation();
		return 1;*/
	}
	return 0;
}

SimpleEnemy::SimpleEnemy() : GameObject("SimpleEnemy")
{
	
}

void SimpleEnemy::Spawn()
{
	float rand_x, rand_y;
	float rand_angle;
	this->setPosition(rand_x, rand_y);
	this->Rotate(rand_angle);
	this->ChooseRandDirection();
}

void SimpleEnemy::ChooseRandDirection()
{
	SplinePath<FPoint> spline;

	float newDirection;
	float rand_angle;
	rand_angle = _angle + 120.0f;
}

void SimpleEnemy::DeathAnimation()
{

}