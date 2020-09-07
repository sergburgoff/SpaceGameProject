#include "MovableTarget.h"
#pragma once
class Bullet : MovableTarget
{
public:
	Bullet();
protected:
	void setDiraction() override;
	void DeathAnimation() override;
};

