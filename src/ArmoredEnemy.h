#pragma once
#include "SimpleEnemy.h"
class ArmoredEnemy : public SimpleEnemy
{
	ArmoredEnemy();
	void Hit() override;
};

