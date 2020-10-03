#include "stdafx.h"
#include "Bullet.h"
#include "Settings.h"

Bullet::Bullet() : MovableTarget("Bullet")
{
	speed = Settings::BULLET_SPEED; //8.0f;
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
