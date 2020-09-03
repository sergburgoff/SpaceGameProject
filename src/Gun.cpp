#include "stdafx.h"
#include "Gun.h"

void Gun::Draw()
{
	FPoint mouse_pos = Core::mainInput.GetMousePos();

	_angle = (mouse_pos.y - y) / (mouse_pos.x - x);
	_angle = math::tan(_angle);
	Render::device.PushMatrix();
	//Render::device.MatrixTranslate(x, y, 0);
	//Render::device.MatrixRotate(math::Vector3(0, 0, 1), _angle);
	//Render::device.MatrixTranslate(x - width / 2, y - hight / 2, 0);
	//_texture->Bind();
	//Render::DrawQuad();
	//Render::DrawRect(x - width / 2, y - hight / 2, width, hight);
	Render::device.MatrixTranslate(x, y, 0);
	Render::device.MatrixRotate(math::Vector3(0, 0, 1), _angle);
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