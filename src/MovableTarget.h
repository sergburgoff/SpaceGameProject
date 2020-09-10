#include "GameObject.h"
#pragma once
class MovableTarget : public GameObject
{
public:
	MovableTarget(std::string _texture) : GameObject(_texture) {}
	virtual void Move();

	virtual bool CheckWallCollision();
	virtual void onCollision() = 0;
	virtual void Destroy() = 0;

	virtual void chargeObjectShield();
	virtual void chargeWallShield();
	virtual void decreaseShield();
	virtual bool isObjectShieldOn();
	virtual bool isWallShieldOn();

protected:
	virtual void DeathAnimation() = 0;
	virtual void setDirection() {}
public:
	const std::string type;
protected:
	float speed;
	size_t collisionObj_shield;
	size_t collisionWall_shield;
};

