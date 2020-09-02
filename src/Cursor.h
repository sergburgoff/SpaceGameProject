#include "GameObject.h"
#pragma once
class Cursor : GameObject
{
public:
	Cursor();
	enum State 
	{
		PASSIVE,
		ACTIVE,
		AIM,
		RELOAD
	};
	void ChangeState(State newState);
	
	void Draw(float pos_x, float pos_y) override;

private:
	State currentState;
};

