#include "stdafx.h"
#include "Gun.h"


void Gun::Aim()
{
	IPoint mouse_pos = Core::mainInput.GetMousePos();

	Render::device.PushMatrix();
	Render::device.MatrixTranslate(mouse_pos.x, mouse_pos.y, 0);
	_texture->Draw();
	Render::device.PopMatrix();
}

void Gun::Reload()
{}

void Gun::DeathAnimation()
{}