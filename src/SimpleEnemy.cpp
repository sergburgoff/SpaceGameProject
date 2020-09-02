#include "stdafx.h"
#include "SimpleEnemy.h"

bool SimpleEnemy::CheckCollision(GameObject &one, GameObject &two)
{
	if (one->x < two->x + two->scale_x &&
		one->x + one->scale_x > two->x &&
		one->y < two->y + two->scale_y &&
		one->y + one->scale_y > two->y)
	{
		return true;
	}
}