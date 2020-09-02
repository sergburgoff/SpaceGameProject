#pragma once
#include "GameObject.h"
class SimpleEnemy : GameObject
{
public:
	SimpleEnemy();
	void Movement();
	bool CheckCollision(GameObject &one, GameObject &two);
protected:
	void ChangeDirection();
};

