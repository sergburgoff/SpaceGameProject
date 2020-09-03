#include "GameObject.h"
#pragma once
class Cursor : GameObject
{
public:
	Cursor() : GameObject("CURSOR_AIM") {};
	enum State 
	{
		PASSIVE,
		ACTIVE,
		AIM,
		RELOAD
	};
	void ChangeState(State newState);
	void DeathAnimation() override {}
	void Draw() override;

private:
	float width = hight = 50.0f;
	State currentState;
};

