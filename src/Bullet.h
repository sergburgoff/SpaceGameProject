#include "MovableTarget.h"
#pragma once
class Bullet : public MovableTarget
{
public:
	Bullet();
	void onCollision() override;
protected:
	void setDirection() override;
};

