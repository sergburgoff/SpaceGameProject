#pragma once
#include "GameObject.h"
class SimpleEnemy : public GameObject
{
public:
	SimpleEnemy();
	bool CheckCollision(GameObject &other) override;

	void Spawn();
	void ChooseRandDirection();

	void DeathAnimation() override;
protected:
	float currentDirection = 0;
	void ChangeDirection();
};

