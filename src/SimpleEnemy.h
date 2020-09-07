#pragma once
#include "MovableTarget.h"
class SimpleEnemy : public MovableTargets
{
public:
	SimpleEnemy();
	
	void onCollision();
	void Destroy() override;
	void DeathAnimation() override;
protected:
	void setDirection() override;
	int Random(int min, int max);
	float Random(float min, float max);
};

