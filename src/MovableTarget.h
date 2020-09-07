#include "GameObject.h"
#pragma once
class MovableTarget : public GameObject
{
public:
	MovableTarget(std::string _texture) : GameObject(_texture) {}
	virtual void Move();
	virtual void onCollision() = 0;
	virtual void Destroy() = 0;
protected:
	virtual void DeathAnimation() = 0;
	void setDirection() {}
public:
	const std::string type;
protected:
	float speed;
};

