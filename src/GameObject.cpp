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

Render::Texture& GameObject::getTexture()
{
	return *_texture;
}

void GameObject::Draw(float pos_x, float pos_y)
{
	Render::device.PushMatrix();
	//Render::device.MatrixTranslate(pos_x, pos_y, 0);
	//Render::device.MatrixRotate(math::Vector3(0, 0, 1), _angle);
	//Render::device.MatrixScale(scale_x, scale_y, 1.5f);
	Render::device.PopMatrix();
	_texture->Bind();
	Render::DrawRect(pos_x, pos_y, 1000, 100);
	
	//_texture->Draw();
}

bool GameObject::CheckCollision(GameObject &one, GameObject &two)
{
	return (one.x < two.x + two.scale_x &&
		one.x + one.scale_x > two.x &&
		one.y < two.y + two.scale_y &&
		one.y + one.scale_y > two.y);
}