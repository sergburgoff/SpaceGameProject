#pragma once
#include "GameObject.h"
class SimpleEnemy : public GameObject
{
public:
	SimpleEnemy();
	bool CheckCollision(GameObject &other) override;
 
	int Random(int min, int max);
	float Random(float min, float max);
	void Spawn(float x, float y, float _angle);
	void ChooseRandDirection();

	void DeathAnimation() override;

protected:
	
	float currentDirection = 0;
	void ChangeDirection();
};

