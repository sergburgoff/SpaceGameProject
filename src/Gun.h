#include "GameObject.h"
#pragma once

class Gun : public GameObject
{
public:
	Gun();
	void Draw() override;
	
	//
	// Проверка, закончилась ли презарядка
	//
	bool isReadyToFire();

	//
	// Перезарядка
	//
	void Reloading();

	//
	// Метод, вызываемый при выстреле, начинающий перезарядку орудия
	//
	void beginReload();

private:
	size_t _reload;
};

