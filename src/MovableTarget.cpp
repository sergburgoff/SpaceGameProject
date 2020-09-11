#include "stdafx.h"
#include "GameObject.h"
#include "MovableTarget.h"
#include "Settings.h"



void MovableTarget::Move()
{
	y = y + speed * math::sin(_angle * (math::PI / 180));
	x = x + speed * math::cos(_angle * (math::PI / 180));
}

bool MovableTarget::CheckWallCollision()
{
	return x + width > RIGHT_BORDER ||
		y + height > Settings::TOP_BORDER ||
		y < Settings::BOTTOM_BORDER || x < Settings::LEFT_BORDER;
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
