#include "GameObject.h"
#pragma once
class Gun : public GameObject
{
public:
	Gun(std::string texture_name) : GameObject(texture_name) {};
	void Reload();
	void Aim();
	void DeathAnimation() override;
	//Animation
	//Rotation
};

