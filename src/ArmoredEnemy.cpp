#include "stdafx.h"
#include "ArmoredEnemy.h"
#include "Settings.h"

ArmoredEnemy() : SimpleEnemy()
{
	setTexture("ArmoredEnemy");
	speed = Settings::AMRORED_ENEMIES_SPEED;
	_hitPoints = 2;
}
void SimpleEnemy::Hit()
{
	if (_hitPoints != 0)
		--_hitPoints;

	if (_hitPoints == 1)
		setTexture("ArmoredEnemyDamaged");
}