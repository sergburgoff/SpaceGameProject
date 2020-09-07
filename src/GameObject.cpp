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

void GameObject::setPosition(float x, float y)
{
	this->x = x;
	this->y = y;
}

void GameObject::Rotate(float _angle)
{
	this->_angle = _angle;
}

void GameObject::Scale(float width, float hight)
{
	this->width = width;
	this->hight = hight;
}

void GameObject::Draw()
{
	Render::device.PushMatrix();
	//Render::device.MatrixTranslate(pos_x, pos_y, 0);
	//Render::device.MatrixRotate(math::Vector3(0, 0, 1), _angle);
	//Render::device.MatrixScale(scale_x, scale_y, 1.5f);
	Render::device.PopMatrix();
	_texture->Bind();
	Render::DrawRect(x, y, width, hight);
	
	//_texture->Draw();
}

void GameObject::Move(float _time)
{
	FPoint currentPosition = 
		spline.getGlobalFrame(math::clamp(0.0f, 1.0f, _time / 6.0f));
	x = currentPosition.x;
	y = currentPosition.y;
}

bool GameObject::CheckCollision(GameObject &other)
{
	return (this->x < other.x + other.width &&
		this->x + this->width > other.x &&
		this->y < other.y + other.hight &&
		this->y + this->hight > other.y);
}