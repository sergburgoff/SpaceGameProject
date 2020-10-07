#include "stdafx.h"
#include "Bullet.h"
#include "Settings.h"

Bullet::Bullet(float x, float y) : MovableTarget("Bullet")
{
	//
	// Звуковой эффект выстрела
	//
	MM::manager.PlaySample("ShotSound");

	this->x = x;
	this->y = y;

	//
	// Устанавливается скорость снаряда, взятая из текстового файла
	//
	_speed = Settings::BULLET_SPEED; //8.0f;

	// 
	// Определяется направление движеня снаряда
	//
	setDirection();
}

Bullet::~Bullet()
{
	//
	// Звуковой эффект взрыва, в случае столкновения с целью или стеной
	//
	MM::manager.PlaySample("ExplosionSound");
}

void Bullet::setDirection()
{
	//
	// Направление снаряда определяется на основе положения
	// мышки
	//

	FPoint mouse_pos = Core::mainInput.GetMousePos();
	float rel_x = mouse_pos.x - x;
	float rel_y = mouse_pos.y - y;
	_angle = (180/math::PI) * math::atan(rel_y, rel_x);
}

void Bullet::onCollision()
{
}
