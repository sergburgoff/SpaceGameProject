#include "stdafx.h"
#include "GameObject.h"
#include "MovableTarget.h"

void MovableTarget::Move()
{
	y = y + speed;
	x = y * math::tan(_angle);
}