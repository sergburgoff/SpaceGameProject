#include "stdafx.h"
#include "GameObject.h"
#include "Settings.h"


GameObject::GameObject(std::string texture_name) 
	: x(0)
	, y(0)
	, width(0)
	, height(0)
	, _angle(0)
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
void GameObject::Scale(float width, float hight)
{
	this->width = width;
	this->height = hight;
}

float GameObject::getX()
{
	return x;
}

float GameObject::getY()
{
	return y;
}

float GameObject::getWidth()
{
	return width;
}

float GameObject::getHeight()
{
	return height;
}

void GameObject::Draw()
{
	Render::device.PushMatrix();
	_texture->Bind();
	Render::DrawRect(x, y, width, height);
	Render::device.PopMatrix();
}

bool GameObject::CheckObjectCollision(GameObject *first, GameObject *second)
{
	//
	// ��������, ��������� �� ������������ ���� ��������
	//
	return (first->getX() < second->getX() + second->getWidth() - SIZE_COEF &&
		first->getX() + first->getWidth() - SIZE_COEF > second->getX() &&
		first->getY() < second->getY() + second->getHeight() - SIZE_COEF &&
		first->getY() + first->getHeight() - SIZE_COEF > second->getY());
}
