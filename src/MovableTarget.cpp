#include "stdafx.h"
#include "GameObject.h"
#include "MovableTarget.h"
#include "Settings.h"



void MovableTarget::Move()
{
	//
	// Объект смещается в соседние координаты со скоростью _speed
	// по вектору, который получается на основе _angle
	//

	y = y + _speed * math::sin(_angle * (math::PI / 180));
	x = x + _speed * math::cos(_angle * (math::PI / 180));
}

bool MovableTarget::CheckWallCollision()
{
	//
	// Проверка, столкнулся ли объект со стеной
	//
	return x + width > Settings::RIGHT_BORDER ||
		y + height > Settings::TOP_BORDER ||
		y < Settings::BOTTOM_BORDER || x < Settings::LEFT_BORDER;
}
