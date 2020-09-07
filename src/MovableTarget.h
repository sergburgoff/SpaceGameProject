#include "GameObject.h"
#pragma once
class MovableTarget : public GameObject
{
public:
	MovableTarget(std::string _texture) : GameObject(_texture) {}
	void Move(float _timer);
	virtual void onCollision() = 0;
	virtual void Destroy() = 0;
public:
	const std::string type;
protected:
	virtual void DeathAnimation() = 0;
	FPoint getCurrentPos(float _timer);
	void setDirection() {}
protected:
	TimedSpline<FPoint> spline;

};

