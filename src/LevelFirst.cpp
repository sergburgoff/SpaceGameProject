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
	LoadLevelSettings(); // Загрузка настроек уровня
	Init();
}

void LevelFirst::Init()
{
	//
	// Указываются координаты и размеры фонового изображения
	//
	background.setPosition(-20, 0);
	background.Scale(Settings::WINDOW_WIDTH + 25, Settings::WINDOW_HEIGHT + 25);

	//
	// Указываются координаты и размеры орудия
	//
	myGun.setPosition(436.0f, 100.0f);
	myGun.Scale(500.0f, 500.0f);

	ShowCursor(false); // Скрывается курсор

	//
	// Вычисляется общее количество врагов
	//
	_enemiesCount = _simpleEnemiesCount + _armoredEnemiesCount; 

	//
	// Коллекция заполняется новыми врагами.
	//
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
	
	//
	// Таймер устанавливается на старт
	//
	myTimer.ReturnToStartTime(); 
}

bool LevelFirst::LoadLevelSettings()
{
	//
	// Загрузка настроек уровня
	// Количество врагов и время, за которое необходимо пройти данный уровень
	//
	std::ifstream input;

	input.open("base_p/level_1.txt");

	if (!input.is_open())
		return false;

	std::string inLine;

	input >> inLine;
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


void LevelFirst::Draw()
{
	background.Draw();

	//
	// Отрисовка снарядов
	//
	for (size_t cur_bullet = 0; cur_bullet < BulletsCollection.size(); ++cur_bullet)
	{
		BulletsCollection[cur_bullet]->Move(); // Перемещение снарядов по полю
		BulletsCollection[cur_bullet]->Draw(); // Отрисовка снарядов в новом их положении

		if (BulletsCollection[cur_bullet]->CheckWallCollision()) // Проверка, произошло ли столкновение со стеной
		{
			//
			// В случае, если снаряд сталквается со стеной, он взрывается и удаляется
			//
			std::vector<Bullet*>::iterator bullet = BulletsCollection.begin() + cur_bullet;
			
			SetEffect("Explosion", BulletsCollection[cur_bullet]->getX()
				+ BulletsCollection[cur_bullet]->getWidth() * 0.5, BulletsCollection[cur_bullet]->getY()
				+ BulletsCollection[cur_bullet]->getHeight() * 0.5);

			delete BulletsCollection[cur_bullet];

			BulletsCollection.erase(bullet);
		}
	}

	myGun.Draw(); // Отрисовка пушки

	//
	// Отрисовка врагов
	//
	for(size_t cur_enemy = 0; cur_enemy < EnemiesCollection.size(); ++cur_enemy)
	{
		EnemiesCollection[cur_enemy]->Draw(); // Отрисовка врага
		
		//
		// Перемещение его координат. 
		// Враг пермещается после отрисовки, чтобы враг оттолкунлся раньше,
		// чем заехал краем на другой объект.
		//
		EnemiesCollection[cur_enemy]->Move(); 

		//
		// Если враг был невосприимчив к столкновеням, то время
		// его невосприимчивости уменьшается
		//
		EnemiesCollection[cur_enemy]->decreaseShield(); 

		//
		// Проверка столкновения со стенами
		//
		if (EnemiesCollection[cur_enemy]->CheckWallCollision() && !EnemiesCollection[cur_enemy]->isWallShieldOn())
		{
			//
			// В случае столкновения, враг меняет направление и временно
			// становится невосприимчивым к столкновениям со стенами
			//
			EnemiesCollection[cur_enemy]->onCollision();
			EnemiesCollection[cur_enemy]->chargeWallShield();
		}
		
		//
		// Проверка столкновения с другими врагами
		//
		for (other_enemy = EnemiesCollection.begin() + cur_enemy + 1; 
			other_enemy != EnemiesCollection.end(); ++other_enemy)
		{
			//
			// В случае столкновения с другим врагом, объект меняет свое направление и становится 
			// невосприимчивым к столкновениям с другими врагами
			//
			if (GameObject::CheckObjectCollision(EnemiesCollection[cur_enemy], *other_enemy) && 
				!EnemiesCollection[cur_enemy]->isObjectShieldOn())
			{
				EnemiesCollection[cur_enemy]->onCollision();
				EnemiesCollection[cur_enemy]->chargeObjectShield();
			}
		}

		//
		// Проверка столкновения со снарядами
		//
		for (size_t cur_bullet = 0; cur_bullet < BulletsCollection.size(); ++cur_bullet)
		{

			//
			// В случае столкновения врага со снарядом, у врага понижаются жизни,
			// а снаряд моментально уничтожается
			//
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

				//
				// В случае, если жизни врага упали до 0, враг уничтожается
				//
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

	//
	// Отрисовка курсора
	//
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

	//
	// Вывод на экран, сколько времени еще осталось
	//
	Render::PrintString(800.0f, 750.0f, "Time left: " + utils::lexical_cast(myTimer.getCurrTime()), 3.f, CenterAlign); 

	//
	// В случае, если время вышло и игрок еще не победил, выводится сообщение о том,
	// что игрок проиграл
	//
	if (myTimer.getCurrTime() == 0 && !isWin)
	{
		Render::PrintString(500.f, 500.f, "You Lose!", 3.f, CenterAlign);
		Render::PrintString(500.f, 400.f, "Press \"R\" to restart", 2.f, CenterAlign);
	}

	//
	// В случае, если все враги уничтожены и игрок еще не проиграл, выводится сообщение о том,
	// что игрок выиграл
	//
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
	//
	// В случае, если игрок нажал на ЛКМ, то производится выстрел
	// После выстрела начинается перезарядка
	//
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
	//
	// В случае, если игрок нажал на "R" или "К", производится
	// перезапуск уровня.
	//
	if (unicodeChar == 114 || unicodeChar == 82 || unicodeChar == 1082 || unicodeChar == 1050)
	{
		//
		// В самом начале удаляются все враги и снаряды, что все еще пристутствуют
		// в памяти
		//
		ClearScreen(); 

		Init(); // Производится инициализация
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
