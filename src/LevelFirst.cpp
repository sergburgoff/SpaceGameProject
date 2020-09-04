#include "stdafx.h"
#include <vector>
#include "LevelFirst.h"
#include "GameObject.h"
#include "Gun.h"
#include "Cursor.h"
#include "SimpleEnemy.h"


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
	
	ShowCursor(false);

	for (size_t i = 0; i < EnemiesCount; ++i)
	{
		SimpleEnemy * newEnemy = new SimpleEnemy();
		MovableTargets.push_back(newEnemy);
	}
}

void LevelFirst::Draw()
{
	Gun myGun;
	myGun.setPosition(436.0f, 100.0f); // 436
	myGun.Scale(500.0f, 500.0f);
	myGun.Draw();	
	
	for (auto &iterator : MovableTargets)
	{
		iterator->Draw();
	}

	Cursor myCursor;
	myCursor.Draw();

	/*
	for (auto &iterator : MovableTargets)
	{
		for (size_t i = 0; i < EnemiesCount; ++i)
		{
			iterator->CheckCollision(*(MovableTargets[i]));
		}
	}*/




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
