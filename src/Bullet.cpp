#include "stdafx.h"
#include "Bullet.h"

Bullet::Bullet(FPoint &mouse_pos) : MovableTarget("Bullet"),
	speed(10.0f)
{
	//spline.addKey(0.0f, FPoint());
	setDirection(mouse_pos);
}

void Bullet::setDirection(FPoint &mouse_pos)
{

}

void Bullet::onCollision()
{

}

void Bullet::Destroy()
{

}

void Bullet::DeathAnimation()
{}