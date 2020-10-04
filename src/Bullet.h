#include "MovableTarget.h"
#pragma once
class Bullet : public MovableTarget
{
public:
	Bullet(float x, float y);
	~Bullet();
	void onCollision() override;

protected:
	void setDirection() override;
};

