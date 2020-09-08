#include "stdafx.h"
#include "GameObject.h"
#include "MovableTarget.h"

void MovableTarget::Move()
{
	float temp = math::sin(_angle);
	float temp1 = math::cos(_angle);
	y = y + speed * math::sin(_angle);
	x = x + speed * math::cos(_angle);
}