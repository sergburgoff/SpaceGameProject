#include "stdafx.h"
#include "LevelFirst.h"
#include "GameObject.h"
#include "Gun.h"
#include "Cursor.h"
#include "SimpleEnemy.h"
#include <vector>

LevelFirst::LevelFirst(const std::string& name, rapidxml::xml_node<>* elem)
	: Widget(name)
	, _curTex(0)
	, _timer(0)
	, _angle(0)
	, _eff(NULL)
	, _scale(0.f)
{
	Init();
}

void LevelFirst::Init()
{
	int EnemiesCount = 10;
	std::vector<GameObject> MovableTargets;

	for (size_t i = 0; i < EnemiesCount; ++i)
	{
		MovableTargets.push_back(new SimpleEnemy());
	}
}

void LevelFirst::Draw()
{
	Gun myGun("Gun");
	myGun.Draw(0, 0);

	Cursor cursor();

	for (GameObject* iterator : MovableTargets)
	{
		iterator->Draw();
	}

	for (GameObject* i : MovableTargets)
	{
		for (GameObject* j : MovableTargets)
		{
			GameObject::CheckCollision(*i, *j);
		}
	}

	Render::device.SetTexturing(false);

	IPoint mouse_pos = Core::mainInput.GetMousePos();
	
	Render::BeginColor(Color(255, 128, 0, 255));

	
	Render::DrawRect(924, 0, 100, 100);

	
	Render::EndColor();

	
	Render::device.SetTexturing(true);

	//
	// Рисуем все эффекты, которые добавили в контейнер (Update() для контейнера вызывать не нужно).
	//
	//_effCont.Draw();

	Render::BindFont("arial");
	Render::PrintString(924 + 100 / 2, 35, utils::lexical_cast(mouse_pos.x) + ", " + utils::lexical_cast(mouse_pos.y), 1.f, CenterAlign);

}

void LevelFirst::Update(float dt)
{
	
}

bool LevelFirst::MouseDown(const IPoint &mouse_pos)
{
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
