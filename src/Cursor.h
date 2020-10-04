#include "GameObject.h"
#pragma once
class Cursor : public GameObject
{
public:
	Cursor();
	enum State 
	{
		PASSIVE,
		ACTIVE,
		AIM,
	};
	void ChangeState(State newState);
	void Draw() override;

private:
	float width, height;
	State _currentState;
};

