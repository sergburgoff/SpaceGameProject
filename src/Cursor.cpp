#include "stdafx.h"
#include "Cursor.h"

Cursor::Cursor() 
	: GameObject("CURSOR_AIM"),
	height(50.0f),
	width(50.0f)
{}

void Cursor::ChangeState(State newState)
{}

void Cursor::Draw()
{
	IPoint mouse_pos = Core::mainInput.GetMousePos();
	switch (_currentState)
	{
	case PASSIVE:
		setTexture("CURSOR_PASSIVE");
		break;
	case ACTIVE:
		setTexture("CURSOR_ACTIVE");
		break;
	case AIM:
		setTexture("CURSOR_AIM");
		break;
	}

	Render::device.PushMatrix();
	_texture->Bind();
	Render::DrawRect((float)mouse_pos.x - width / 2,
		(float)mouse_pos.y - height / 2, width, height);
	Render::device.PopMatrix();
}