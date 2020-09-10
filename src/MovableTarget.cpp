#include "stdafx.h"
#include "GameObject.h"
#include "MovableTarget.h"

#define SIZE_COEF 15.f

enum { // ÓÁÐÀÒÜ!
	BOTTOM_BORDER = 60,
	TOP_BORDER = 755,
	RIGHT_BORDER = 1000,
	LEFT_BORDER = -10
};

void MovableTarget::Move()
{
	y = y + speed * math::sin(_angle * (math::PI / 180));
	x = x + speed * math::cos(_angle * (math::PI / 180));
}

bool MovableTarget::CheckWallCollision()
{
	return x + width > RIGHT_BORDER ||
		y + height > TOP_BORDER ||
		y < BOTTOM_BORDER || x < LEFT_BORDER;
}

void MovableTarget::chargeObjectShield()
{
	collisionObj_shield = 5;
}

void MovableTarget::chargeWallShield()
{
	collisionWall_shield = 10;
}

void MovableTarget::decreaseShield()
{
	if (collisionObj_shield != 0)
		--collisionObj_shield;
	if (collisionWall_shield != 0)
		--collisionWall_shield;

}

bool MovableTarget::isObjectShieldOn()
{
	return collisionObj_shield != 0;
}

bool MovableTarget::isWallShieldOn()
{
	return collisionWall_shield != 0;
}
