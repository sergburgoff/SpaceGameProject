#include "MovableTarget.h"
#pragma once
class Bullet : public MovableTarget
{
public:
	Bullet(float x, float y);
	void onCollision() override;
protected:
	void setDirection() override;
};

