#include "GameObject.h"
#pragma once
class MovableTarget : public GameObject
{
public:
	MovableTarget(std::string _texture) : GameObject(_texture) {}
	void Move(float _timer);

	virtual void Destroy() = 0;
	
	virtual void DeathAnimation() = 0;

protected:
	FPoint getCurrentPos(float _timer);
	virtual void setDirection(float _timer) = 0;
protected:
	TimedSpline<FPoint> spline;

};

