#pragma once
#include "SimpleEnemy.h"
class ArmoredEnemy : public SimpleEnemy
{
public:
	ArmoredEnemy();
	void Hit() override;
};

