#include "GameObject.h"
#pragma once
class Gun : public GameObject
{
public:
	Gun();
	void Reload();
	void Draw() override;
	//Animation
};

