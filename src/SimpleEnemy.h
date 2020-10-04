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

	virtual void chargeObjectShield();
	virtual void chargeWallShield();
	virtual void decreaseShield();
	virtual bool isObjectShieldOn();
	virtual bool isWallShieldOn();

protected:
	void setDirection() override;
	int Random(int min, int max);
	float Random(float min, float max);

protected:
	size_t _hitPoints;
	size_t _collisionObj_shield;
	size_t _collisionWall_shield;
};

