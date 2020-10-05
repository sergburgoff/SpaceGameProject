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
#include "Settings.h"
#include <iostream>
#include <fstream>

//#define DEBUG

LevelFirst::LevelFirst(const std::string& name, rapidxml::xml_node<>* elem)
	: Widget(name)
	, _timer(0)
	, _eff(NULL)
{
	LoadLevelSettings();
	Init();
}

void LevelFirst::Init()
{
	background.setPosition(-20, 0);
	background.Scale(Settings::WINDOW_WIDTH + 25, Settings::WINDOW_HEIGHT + 25);

	myGun.setPosition(436.0f, 100.0f);
	myGun.Scale(500.0f, 500.0f);

	ShowCursor(false);

	_enemiesCount = _simpleEnemiesCount + _armoredEnemiesCount;

	for (size_t i = 0; i < _simpleEnemiesCount; ++i)
	{
		SimpleEnemy * newEnemy = new SimpleEnemy();
		newEnemy->Scale(70.0f, 70.0f);
		EnemiesCollection.push_back(newEnemy);
	}
	for (size_t i = 0; i < _armoredEnemiesCount; ++i)
	{
		ArmoredEnemy * newEnemy = new ArmoredEnemy();
		newEnemy->Scale(90.0f, 90.0f);
		EnemiesCollection.push_back(newEnemy);
	}
	
	myTimer.ReturnToStartTime();
}

void LevelFirst::Draw()
{
	background.Draw();

	for (size_t cur_bullet = 0; cur_bullet < BulletsCollection.size(); ++cur_bullet)
	{
		BulletsCollection[cur_bullet]->Move();
		BulletsCollection[cur_bullet]->Draw();
		if (BulletsCollection[cur_bullet]->CheckWallCollision())
		{
			std::vector<Bullet*>::iterator bullet = BulletsCollection.begin() + cur_bullet;
			
			SetEffect("Explosion", BulletsCollection[cur_bullet]->getX()
				+ BulletsCollection[cur_bullet]->getWidth() * 0.5, BulletsCollection[cur_bullet]->getY()
				+ BulletsCollection[cur_bullet]->getHeight() * 0.5);

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
				
				SetEffect("Explosion", BulletsCollection[cur_bullet]->getX()
					+ BulletsCollection[cur_bullet]->getWidth() * 0.5, BulletsCollection[cur_bullet]->getY()
					+ BulletsCollection[cur_bullet]->getHeight() * 0.5);

				delete BulletsCollection[cur_bullet];
				BulletsCollection.erase(bullet);
				
				SetEffect("ArmorDestroy", EnemiesCollection[cur_enemy]->getX()
					+ EnemiesCollection[cur_enemy]->getWidth() * 0.5, EnemiesCollection[cur_enemy]->getY()
					+ EnemiesCollection[cur_enemy]->getHeight() * 0.5);

				EnemiesCollection[cur_enemy]->Hit();

				if (EnemiesCollection[cur_enemy]->getCurrentHitPoints()
					== 0)
				{
					SetEffect("Explosion", EnemiesCollection[cur_enemy]->getX()
						+ EnemiesCollection[cur_enemy]->getWidth() * 0.5, EnemiesCollection[cur_enemy]->getY()
						+ EnemiesCollection[cur_enemy]->getHeight() * 0.5);

					delete EnemiesCollection[cur_enemy];
					EnemiesCollection.erase(enemy);
					--_enemiesCount;
				}
				break;
			}
		}
	}

	myCursor.Draw();
	//
	// Рисуем все эффекты, которые добавили в контейнер (Update() для контейнера вызывать не нужно).
	//
	_effCont.Draw();

	Render::BindFont("arial");

#ifdef DEBUG
	IPoint mouse_pos = Core::mainInput.GetMousePos();

	Render::device.SetTexturing(false);
	Render::BeginColor(Color(255, 128, 0, 255));
	Render::DrawRect(924, 0, 100, 100);
	Render::EndColor();
	Render::device.SetTexturing(true);

	Render::PrintString(924 + 100 / 2, 35, utils::lexical_cast(mouse_pos.x) + ", " + utils::lexical_cast(mouse_pos.y), 1.f, CenterAlign);
#endif

	Render::PrintString(800.0f, 750.0f, "Time left: " + utils::lexical_cast(myTimer.getCurrTime()), 3.f, CenterAlign);

	if (myTimer.getCurrTime() == 0 && !isWin)
	{
		Render::PrintString(500.f, 500.f, "You Lose!", 3.f, CenterAlign);
		Render::PrintString(500.f, 400.f, "Press \"R\" to restart", 2.f, CenterAlign);
	}

	if (_enemiesCount == 0 && !isLose)
	{
		Render::PrintString(500.f, 550.f, "You Win!", 3.f, CenterAlign);
		Render::PrintString(500.f, 400.f, "Press \"R\" to restart", 2.f, CenterAlign);
	}
}

void LevelFirst::Update(float dt)
{

	_effCont.Update(dt);

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

void LevelFirst::SetEffect(std::string effect_name, float x, float y)
{
	_eff = _effCont.AddEffect(effect_name);
	_eff->posX = x;
	_eff->posY = y;
	_eff->Reset();

	if (_eff)
	{
		//
		// Если эффект создан, то при отпускании мыши завершаем его.
		//
		_eff->Finish();
		_eff = NULL;
		_effCont.Finish();
	}

}

bool LevelFirst::MouseDown(const IPoint &mouse_pos)
{
	if (Core::mainInput.GetMouseLeftButton() && myGun.isReadyToFire())
	{
		Bullet * newBullet = new Bullet(415.0f, 88.0f); //425
		newBullet->Scale(50.0f, 50.0f);

		BulletsCollection.push_back(newBullet);
		myGun.beginReload();
	}
	return true;
}

void LevelFirst::CharPressed(int unicodeChar)
{
	if (unicodeChar == 114 || unicodeChar == 82 || unicodeChar == 1082 || unicodeChar == 1050)
	{
		ClearScreen();
		Init();
	}
}

void LevelFirst::ClearScreen()
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
}

bool LevelFirst::LoadLevelSettings()
{
	std::ifstream input;

	input.open("base_p/level_1.txt"); // Не уверен, что так корректно

	if (!input.is_open())
		return false;

	std::string inLine;

	input >> inLine; // Стоит сделать как-нибудь умнее))
	input >> inLine;
	_simpleEnemiesCount = std::stof(inLine);
	input >> inLine;
	input >> inLine;
	_armoredEnemiesCount = std::stof(inLine);
	input >> inLine;
	input >> inLine;
	myTimer.setStartTime(std::stof(inLine));

	input.close();

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
