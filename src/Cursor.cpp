#include "stdafx.h"
#include "Cursor.h"

void Cursor::Draw(float pos_x, float pos_y)
{
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
	Render::device.MatrixTranslate(pos_x, pos_y, 0);
	_texture->Draw();
	Render::device.PopMatrix();
}