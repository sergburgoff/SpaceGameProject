#include "MovableTarget.h"
#pragma once
class Bullet : public MovableTarget
{
public:
	Bullet();
	void onCollision() override;
	void Destroy() override;
protected:
	void setDirection() override;
	void DeathAnimation() override;
};

