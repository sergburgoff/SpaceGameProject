#pragma once
#include "MovableTarget.h"
class SimpleEnemy : public MovableTarget
{
public:
	SimpleEnemy();

	void Move() override;
	void onCollision() override;

	//
	// Вызывается при попадании по цели
	//
	virtual void Hit();

	//
	// Возвращает оставшееся количество жизней у цели
	//
	virtual size_t getCurrentHitPoints();

	bool CheckWallCollision() override;

	//
	// В случае столкновения с другой целью включается невосприимчивость
	//  объекта к столкновениям с другими объектами
	//
	virtual void chargeObjectShield(); 

	//
	// В случае столкновения со стеной включается невосприимчивость 
	// объекта к столкновениям со стенами
	//
	virtual void chargeWallShield();

	//
	// Отсчитывается время до того, как
	// объект снова станет воосприимчивым к столкновениям
	//
	virtual void decreaseShield();

	//
	// Проверка, включена ли еще невосприимчивость
	// объекта к столкновениям
	//
	virtual bool isObjectShieldOn();
	virtual bool isWallShieldOn();

protected:
	void setDirection() override;

	int Random(int min, int max);
	float Random(float min, float max);

protected:
	size_t _hitPoints; // Количество жизней цели.
	size_t _collisionObj_shield; 
	size_t _collisionWall_shield;
};

