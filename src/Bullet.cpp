#include "stdafx.h"
#include "Bullet.h"

Bullet::Bullet() : MovableTarget("Bullet") 
{
	//spline.addKey(0.0f, FPoint());
	setDiraction();
}

void Bullet::setDiration(FPoint mouse_pos)
{
	spline.addKey(1.0f, mouse_pos);
	spline.CalculateGradient();
}

void Bullet::DeathAnimation()
{}