#include "stdafx.h"
#include <stdlib.h>
#include <vector>
#include "GameObject.h"
#include "Gun.h"
#include "Cursor.h"
#include "SimpleEnemy.h"
#include "ArmoredEnemy.h"
#include "MovableTarget.h"
#include "Bullet.h"
#include "LevelFirst.h"
#include "gameTimer.h"
#include <iostream>
#include <fstream>

LevelFirst::LevelFirst(const std::string& name, rapidxml::xml_node<>* elem)
	: Widget(name)
	, _timer(0)
	, _eff(NULL)
{
	Init();
}

void LevelFirst::Init()
{
	Deserialisation();

	myGun.setPosition(436.0f, 100.0f);
	myGun.Scale(500.0f, 500.0f);

	ShowCursor(false);

	_enemiesCount = _simpleEnemiesCount + _armoredEnemiesCount;

	for (size_t i = 0; i < _simpleEnemiesCount; ++i)
	{
		SimpleEnemy * newEnemy = new SimpleEnemy();
		EnemiesCollection.push_back(newEnemy);
	}
	for (size_t i = 0; i < _armoredEnemiesCount; ++i)
	{
		ArmoredEnemy * newEnemy = new ArmoredEnemy();
		EnemiesCollection.push_back(newEnemy);
	}
}

void LevelFirst::Draw()
{
	for (size_t cur_bullet = 0; cur_bullet < BulletsCollection.size(); ++cur_bullet)
	{
		BulletsCollection[cur_bullet]->Move();
		BulletsCollection[cur_bullet]->Draw();
		if (BulletsCollection[cur_bullet]->CheckWallCollision())
		{
			std::vector<Bullet*>::iterator bullet = BulletsCollection.begin() + cur_bullet;
			BulletsCollection[cur_bullet]->Destroy();

			delete BulletsCollection[cur_bullet];

			BulletsCollection.erase(bullet);
		}
	}

	myGun.Draw();	

	for(size_t cur_enemy = 0; cur_enemy < EnemiesCollection.size(); ++cur_enemy)
	{
		EnemiesCollection[cur_enemy]->Draw();
		EnemiesCollection[cur_enemy]->Move();

		EnemiesCollection[cur_enemy]->decreaseShield();

		if (EnemiesCollection[cur_enemy]->CheckWallCollision() && !EnemiesCollection[cur_enemy]->isWallShieldOn())
		{
			EnemiesCollection[cur_enemy]->onCollision();
			EnemiesCollection[cur_enemy]->chargeWallShield();
		}
		
		for (other_enemy = EnemiesCollection.begin() + cur_enemy + 1; 
			other_enemy != EnemiesCollection.end(); ++other_enemy)
		{
			if (GameObject::CheckObjectCollision(EnemiesCollection[cur_enemy], *other_enemy) && 
				!EnemiesCollection[cur_enemy]->isObjectShieldOn())
			{
				EnemiesCollection[cur_enemy]->onCollision();
				EnemiesCollection[cur_enemy]->chargeObjectShield();
			}
		}
		for (size_t cur_bullet = 0; cur_bullet < BulletsCollection.size(); ++cur_bullet)
		{
			if (GameObject::CheckObjectCollision(EnemiesCollection[cur_enemy], BulletsCollection[cur_bullet]))
			{
				std::vector<SimpleEnemy*>::iterator enemy = EnemiesCollection.begin() + cur_enemy;
				std::vector<Bullet*>::iterator bullet = BulletsCollection.begin() + cur_bullet;

				delete BulletsCollection[cur_bullet];
				BulletsCollection.erase(bullet);
				
				EnemiesCollection[cur_enemy]->Hit();

				if (EnemiesCollection[cur_enemy]->getCurrentHitPoints()
					== 0)
				{
					delete EnemiesCollection[cur_enemy];
					EnemiesCollection.erase(enemy);
					--_enemiesCount;
				}
				break;
			}
		}
	}

	myCursor.Draw();

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
	Render::PrintString(800.0f, 750.0f, "Time left: " + utils::lexical_cast(myTimer.getCurrTime()), 3.f, CenterAlign);

	if (myTimer.getCurrTime() == 0 && !isWin)
	{
		Render::PrintString(500.f, 500.f, "You Lose!", 1.f, CenterAlign);
		Render::PrintString(500.f, 400.f, "Press \"R\" to restart", 1.f, CenterAlign);
	}

	if (_enemiesCount == 0 && !isLose)
	{
		Render::PrintString(500.f, 550.f, "You Lose!", 1.f, CenterAlign);
		Render::PrintString(500.f, 400.f, "Press \"R\" to restart", 1.f, CenterAlign);
	}
}

void LevelFirst::Update(float dt)
{

	_timer += dt *2;

	while (_timer > 2 * math::PI)
	{
		_timer -= 2 * math::PI;
	}

	myTimer.Tick();
	myGun.Reloading();

	if (myTimer.getCurrTime() == 0 && !isWin)
	{
		isLose = true;
	}

	if (_enemiesCount == 0 && !isLose)
	{
		isWin = true;
	}
}

bool LevelFirst::MouseDown(const IPoint &mouse_pos)
{
	if (Core::mainInput.GetMouseLeftButton() && myGun.isReadyToFire())
	{
		Bullet * newBullet = new Bullet();
		BulletsCollection.push_back(newBullet);
		myGun.beginReload();
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
	if (unicodeChar == 114 || unicodeChar == 82)
	{
		for (int i = EnemiesCollection.size() - 1; i >= 0; --i)
		{
			delete EnemiesCollection[i];
			EnemiesCollection.pop_back();
		}

		for (int i = BulletsCollection.size() - 1; i >= 0; --i)
		{
			delete BulletsCollection[i];
			BulletsCollection.pop_back();
		}

		Init();
	}
}

bool LevelFirst::Deserialisation()
{
	std::ifstream input;

	input.open("settings.txt");

	if (!input.is_open())
		return false;

	std::string inLine;

	input >> inLine;
	_simpleEnemiesCount = std::stoi(inLine);
	input >> inLine;
	_armoredEnemiesCount = std::stoi(inLine);
	input >> inLine;
	myTimer.addSeconds(std::stoi(inLine));

	input.close();

	return true;

}
