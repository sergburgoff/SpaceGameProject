#include "GameObject.h"
#pragma once

#define RELOADING_TIME 200;

class Gun : public GameObject
{
public:
	Gun();
	void Draw() override;
	
	bool isReadyToFire();
	void Reloading();
	void beginReload();

	//Animation
private:
	size_t _reload = 0;
};

