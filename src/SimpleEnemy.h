#pragma once
#include "MovableTargets.h"
class SimpleEnemy : public MovableTargets
{
public:
	SimpleEnemy();
	bool CheckCollision(GameObject &other) override;
 
	void ChooseRandDirection();
	void Move();

	void DeathAnimation() override;

protected:

	int Random(int min, int max);
	float Random(float min, float max);

protected:
	float currentDirection = 0;
};

