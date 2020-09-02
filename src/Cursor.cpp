#include "stdafx.h"
#include "Cursor.h"

Cursor::Cursor()
{
	_texture = Core::resourceManager.Get<Render::Texture>("CURSOR_AIM");
}

void Cursor::Draw(float pos_x, float pos_y)
{
	IPoint mouse_pos = Core::mainInput.GetMousePos();
	switch (currentState)
	{
	case PASSIVE:
		this->setTexture("CURSOR_PASSIVE");
		break;
	case ACTIVE:
		this->setTexture("CURSOR_ACTIVE");
		break;
	case AIM:
		this->setTexture("CURSOR_AIM");
		break;
	case RELOAD:
		this->setTexture("CURSOR_RELOAD");
		break;
	}
	Render::device.PushMatrix();
	Render::device.MatrixTranslate(mouse_pos.x, mouse_pos.y, 0);
	_texture->Draw();
	Render::device.PopMatrix();
}