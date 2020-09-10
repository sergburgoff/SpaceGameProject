#include "stdafx.h"
#include "Bullet.h"

Bullet::Bullet() : MovableTarget("Bullet")
{
	speed = 8.0f;
	Scale(50.0f, 50.0f);
	x = 432.0f;
	y = 92.0f; // 100
	setDirection();
}

void Bullet::setDirection()
{
	FPoint mouse_pos = Core::mainInput.GetMousePos();
	float rel_x = mouse_pos.x - x;
	float rel_y = mouse_pos.y - y;
	_angle = (180/math::PI) * math::atan(rel_y, rel_x);
}

void Bullet::onCollision()
{
}

void Bullet::Destroy()
{

}

void Bullet::DeathAnimation()
{}