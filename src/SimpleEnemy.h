#pragma once
#include "MovableTarget.h"
class SimpleEnemy : public MovableTarget
{
public:
	SimpleEnemy();

	void onCollision() override;
	void Destroy() override;
protected:
	void setDirection() override;
	int Random(int min, int max);
	float Random(float min, float max);
	void DeathAnimation() override;
public:
	const std::string type = "SimpleEnemie";
};

