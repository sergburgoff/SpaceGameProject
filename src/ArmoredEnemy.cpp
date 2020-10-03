#include "stdafx.h"
#include "ArmoredEnemy.h"
#include "Settings.h"

ArmoredEnemy::ArmoredEnemy() : SimpleEnemy()
{
	setTexture("ArmoredEnemy");
	speed = Settings::ARMORED_ENEMIES_SPEED;
	_hitPoints = 2;
}
void ArmoredEnemy::Hit()
{
	if (_hitPoints != 0)
		--_hitPoints;

	if (_hitPoints == 1)
		setTexture("ArmoredEnemyDamaged");
}