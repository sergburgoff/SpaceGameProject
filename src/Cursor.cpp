#include "stdafx.h"
#include "Cursor.h"

void Cursor::ChangeState(State newState)
{

}

void Cursor::Draw()
{
	IPoint mouse_pos = Core::mainInput.GetMousePos();
	switch (currentState)
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
	case RELOAD:
		setTexture("CURSOR_RELOAD");
		break;
	}
	Render::device.PushMatrix();
	_texture->Bind();
	Render::DrawRect((float)mouse_pos.x - width / 2,
		(float)mouse_pos.y - hight / 2, width, hight);
	Render::device.PopMatrix();
}