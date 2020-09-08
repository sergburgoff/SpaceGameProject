#include "stdafx.h"
#include <vector>
#include "GameObject.h"
#include "Gun.h"
#include "Cursor.h"
#include "SimpleEnemy.h"
#include "MovableTarget.h"
#include "Bullet.h"
#include "LevelFirst.h"



LevelFirst::LevelFirst(const std::string& name, rapidxml::xml_node<>* elem)
	: Widget(name)
	, _curTex(0)
	, _timer(0)
	, _eff(NULL)
	, _scale(0.f)
	, EnemiesCount(10)
{
	Init();
}

void LevelFirst::Init()
{
	
	ShowCursor(false);

	for (size_t i = 0; i < EnemiesCount; ++i)
	{
		SimpleEnemy * newEnemy = new SimpleEnemy();
		EnemiesCollection.push_back(newEnemy);
	}
}

void LevelFirst::Draw()
{
	Gun myGun;
	myGun.setPosition(436.0f, 100.0f);
	myGun.Scale(500.0f, 500.0f);
	myGun.Draw();	
	
	for (auto &bullet : BulletsCollection)
	{
		bullet->Draw();
		bullet->Move(); // �����������
	}

	size_t i = 0;
	for (auto &iterator : EnemiesCollection)
	{
		++i;
		iterator->Draw();
		iterator->Move();
		
		for (auto other = EnemiesCollection.begin() + i; other != EnemiesCollection.end(); ++other)
		{
			if (GameObject::CheckCollision(iterator, *other))
			{
				iterator->onCollision();
			}
		}
		for (auto &bullet : BulletsCollection)
		{
			if (iterator->CheckCollision(iterator, bullet))
			{
				/*iterator->Destroy();
				bullet->Destroy();
				delete iterator;
				delete bullet;
				//EnemiesCollection.erase(*iterator);
				//BulletsCollection.erase(*bullet);
				continue;*/
			}
		}
	}

	Cursor myCursor;
	myCursor.Draw();

	Render::device.SetTexturing(false);

	IPoint mouse_pos = Core::mainInput.GetMousePos();
	
	Render::BeginColor(Color(255, 128, 0, 255));

	
	Render::DrawRect(924, 0, 100, 100);

	
	Render::EndColor();

	
	Render::device.SetTexturing(true);

	//
	// ������ ��� �������, ������� �������� � ��������� (Update() ��� ���������� �������� �� �����).
	//
	//_effCont.Draw();

	Render::BindFont("arial");
	Render::PrintString(924 + 100 / 2, 35, utils::lexical_cast(mouse_pos.x) + ", " + utils::lexical_cast(mouse_pos.y), 1.f, CenterAlign);

}

void LevelFirst::Update(float dt)
{
	_timer += dt *2;

	while (_timer > 2 * math::PI)
	{
		_timer -= 2 * math::PI;
	}
}

bool LevelFirst::MouseDown(const IPoint &mouse_pos)
{
	if (Core::mainInput.GetMouseLeftButton())
	{
		Bullet * newBullet = new Bullet();
		BulletsCollection.push_back(newBullet);
	}
	return true;
}

void LevelFirst::MouseMove(const IPoint &mouse_pos)
{
	
}

void LevelFirst::MouseUp(const IPoint &mouse_pos)
{
	
}

void LevelFirst::AcceptMessage(const Message& message)
{
	
}

void LevelFirst::KeyPressed(int keyCode)
{
	
}

void LevelFirst::CharPressed(int unicodeChar)
{
	
}
