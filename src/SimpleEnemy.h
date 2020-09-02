#pragma once
#include "GameObject.h"
class SimpleEnemy : GameObject
{
public:
	SimpleEnemy();
	void Movement();
	bool SimpleEnemy::CheckCollision(GameObject &one,
		GameObject &two) override;
	void DeathAnimation() override;
protected:
	void ChangeDirection();
};

