#include "stdafx.h"
#include "Gun.h"

void Gun::Draw()
{
	FPoint mouse_pos = Core::mainInput.GetMousePos();
	float rel_x = mouse_pos.x - x;
	float rel_y = mouse_pos.y - y;
	_angle = (180 / math::PI) * -math::atan(rel_y, rel_x);
	Render::device.PushMatrix();
	Render::device.MatrixTranslate(x, y, 0);
	Render::device.MatrixRotate(math::Vector3(0, 0, 1), -_angle - 90);
	IRect texRect = _texture->getBitmapRect();
	FRect rect(texRect);
	FRect uv(0, 1, 0 , 1);
	_texture->TranslateUV(rect, uv);

	Render::device.MatrixScale(0.150f);
	Render::device.MatrixTranslate(-texRect.width *0.5,
		-texRect.height * 0.5, 0.0f);
	_texture->Bind();
	Render::DrawQuad(rect,uv);
	Render::device.PopMatrix();
}

void Gun::Reload()
{}

void Gun::DeathAnimation()
{}