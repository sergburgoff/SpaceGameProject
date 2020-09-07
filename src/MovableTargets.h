#include "GameObject.h"
#pragma once
class MovableTargets : public GameObject
{
public:
	MovableTargets(std::string _texture) : GameObject(_texture) {}
	void Move(float _timer);
	
	virtual void DeathAnimation() = 0;

protected:
	TimedSpline<FPoint> spline;

};

