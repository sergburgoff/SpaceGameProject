#include "stdafx.h"
#include "Bullet.h"

Bullet::Bullet(FPoint &mouse_pos) : MovableTarget("Bullet") 
{
	//spline.addKey(0.0f, FPoint());
	setDirection(mouse_pos);
}

void Bullet::setDirection(FPoint &mouse_pos)
{
	spline.addKey(1.0f, mouse_pos);
	spline.CalculateGradient();
}

void Bullet::onCollision()
{

}

void Bullet::Destroy()
{

}

void Bullet::DeathAnimation()
{}