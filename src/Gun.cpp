#include "stdafx.h"
#include "Settings.h"
#include "Gun.h"

Gun::Gun() : GameObject("GunReady") 
{
	//
	// Устанавливается время перезарядки, взятое из текстового файла
	// 
	_reload = Settings::RELOADING_TIME;
}

void Gun::Draw()
{
	FPoint mouse_pos = Core::mainInput.GetMousePos();
	float rel_x = mouse_pos.x - x;
	float rel_y = mouse_pos.y - y;

	//
	// Пушка всегда повернута на курсор игрока
	//
	_angle = (180 / math::PI) * math::atan(rel_y, rel_x);

	Render::device.PushMatrix();
	Render::device.MatrixTranslate(x, y, 0);
	Render::device.MatrixRotate(math::Vector3(0, 0, 1), _angle - 90);

	IRect texRect = _texture->getBitmapRect();
	FRect rect(texRect);
	FRect uv(0, 1, 0 , 1);
	_texture->TranslateUV(rect, uv);

	Render::device.MatrixScale(0.23);
	Render::device.MatrixTranslate(-texRect.width *0.5,
		-texRect.height * 0.5, 0.0f);
	_texture->Bind();
	Render::DrawQuad(rect,uv);
	Render::device.PopMatrix();
}

bool Gun::isReadyToFire()
{
	return _reload == Settings::RELOADING_TIME;
}

void Gun::Reloading()
{
	//
	// Определяется текстура в зависимости
	// от того, сколько времени осталось до конца перезарядки
	//
	if (_reload == Settings::RELOADING_TIME)
		setTexture("GunReady"); 

	if (_reload < Settings::RELOADING_TIME * 0.33)
		setTexture("GunReload1");

	if (_reload >= Settings::RELOADING_TIME * 0.33
		&& _reload < Settings::RELOADING_TIME * 0.66)
		setTexture("GunReload2");

	if (_reload >= Settings::RELOADING_TIME * 0.66
		&& _reload < Settings::RELOADING_TIME * 0.99)
		setTexture("GunReload3");

	if(_reload == Settings::RELOADING_TIME - 1)
		MM::manager.PlaySample("ChargeSound");

	//
	// Перезарядка
	//
	if (_reload != Settings::RELOADING_TIME)
		++_reload;
}

void Gun::beginReload()
{
	if (_reload == Settings::RELOADING_TIME)
		_reload = 0;
}
