#include "GameObject.h"
#pragma once
class Gun : public GameObject
{
public:
	Gun() : GameObject("Gun") {};
	void Reload();
	void Draw() override;
	void DeathAnimation() override;
	//Animation
};

