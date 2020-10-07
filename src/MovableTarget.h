#include "GameObject.h"
#pragma once
class MovableTarget : public GameObject
{
public:
	MovableTarget(std::string _texture) : GameObject(_texture) {}
	
	virtual void Move();

	virtual bool CheckWallCollision(); // Проверка столкновения со стенами
	virtual void onCollision() = 0; // Метод, вызываемый при столкновении

protected:
	virtual void setDirection() {} // Выбор направления

protected:
	float _speed;
};

