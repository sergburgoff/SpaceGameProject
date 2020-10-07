#include "stdafx.h"
#include "ArmoredEnemy.h"
#include "Settings.h"

ArmoredEnemy::ArmoredEnemy() : SimpleEnemy()
{
	setTexture("ArmoredEnemy");
	_speed = Settings::ARMORED_ENEMIES_SPEED;
	_hitPoints = 2;
}
void ArmoredEnemy::Hit()
{
	if (_hitPoints != 0)
		--_hitPoints;

	//
	// Если в бронированного врага попали в первый раз,
	// то меняется текстура.
	//

	if (_hitPoints == 1)
		setTexture("ArmoredEnemyDamaged");
}