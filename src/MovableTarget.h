#include "GameObject.h"
#pragma once
class MovableTarget : public GameObject
{
public:
	MovableTarget(std::string _texture) : GameObject(_texture) {}
	virtual void Move();

	virtual bool CheckWallCollision();
	virtual void onCollision() = 0;

protected:
	virtual void setDirection() {}

protected:
	float _speed;
};

