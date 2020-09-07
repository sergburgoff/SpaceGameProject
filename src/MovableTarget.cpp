#include "stdafx.h"
#include "GameObject.h"
#include "MovableTarget.h"


FPoint MovableTarget::getCurrentPos()
{
	return spline.getGlobalFrame(math::clamp(0.0f, 1.0f, _time / 6.0f));
}

void MovableTarget::Move(float _time)
{
	FPoint currentPosition = getCurrentPos(_time);
	x = currentPosition.x;
	y = currentPosition.y;
}