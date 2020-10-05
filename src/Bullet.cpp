#include "stdafx.h"
#include "Bullet.h"
#include "Settings.h"

Bullet::Bullet(float x, float y) : MovableTarget("Bullet")
{
	MM::manager.PlaySample("ShotSound");

	this->x = x;
	this->y = y;

	_speed = Settings::BULLET_SPEED; //8.0f;
	setDirection();
}

Bullet::~Bullet()
{
	MM::manager.PlaySample("ExplosionSound");
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
