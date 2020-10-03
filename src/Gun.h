#include "GameObject.h"
#pragma once

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
	size_t _reload;
};

