#pragma once
#include "MovableTarget.h"
class SimpleEnemy : public MovableTarget
{
public:
	SimpleEnemy();
	void Move() override;
	void onCollision() override;

	virtual void Hit();
	virtual size_t getCurrentHitPoints();
protected:
	void setDirection() override;
	int Random(int min, int max);
	float Random(float min, float max);
protected:
	size_t _hitPoints;
};

