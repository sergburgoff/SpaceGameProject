#include "stdafx.h"
#include "GameObject.h"

GameObject::GameObject(std::string texture_name)
{
	_texture = Core::resourceManager.Get<Render::Texture>(texture_name);
}

void GameObject::setTexture(std::string texture_name)
{
	_texture = Core::resourceManager.Get<Render::Texture>(texture_name);
}

Render::texture & GameObject::getTexture()
{
	return _texture;
}

void GameObject::Draw(float pos_x, float pos_y)
{
	IPoint mouse_pos = Core::mainInput.GetMousePos();

	Render::device.PushMatrix();
	Render::device.MatrixTranslate(pos_x, pos_y, 0);
	Render::device.MatrixRotate(math::Vector3(0, 0, 1), _angle);
	Render::device.MatrixScale(scale_x, scale_y, 1.5f);
	_texture->Draw();
	Render::device.PopMatrix();
}