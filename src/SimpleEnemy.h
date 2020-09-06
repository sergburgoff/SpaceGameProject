#pragma once
#include "GameObject.h"
class SimpleEnemy : public GameObject
{
public:
	SimpleEnemy();
	bool CheckCollision(GameObject &other) override;
 
	void ChooseRandDirection();

	void DeathAnimation() override;

protected:

	int Random(int min, int max);
	float Random(float min, float max);

protected:
	float currentDirection = 0;
};

