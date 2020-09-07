#include "MovableTarget.h"
#pragma once
class Bullet : public MovableTarget
{
public:
	Bullet(FPoint &mouse_pos);
	void onCollision() override;
	void Destroy() override;
protected:
	void setDirection(FPoint &mouse_pos);
	void DeathAnimation() override;
public:
	const std::string type = "Bullet";
protected:
	float speed;
};

