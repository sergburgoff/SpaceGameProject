#pragma once
#include "GameObject.h"
#include "SimpleEnemy.h"
#include "Bullet.h"
#include "gameTimer.h"
#include "Gun.h"
#include "Cursor.h"

class LevelFirst : public GUI::Widget
{
public:
	LevelFirst(const std::string& name, rapidxml::xml_node<>* elem);

	void Draw() override;
	void Update(float dt) override;

	//
	// Очистка экрана от целей, которые еще не были уничтожены
	// Вызывается при рестарте
	//
	void ClearScreen();

	void AcceptMessage(const Message& message) override;

	bool MouseDown(const IPoint& mouse_pos) override;
	void MouseMove(const IPoint& mouse_pos) override;
	void MouseUp(const IPoint& mouse_pos) override;

	void KeyPressed(int keyCode) override;
	void CharPressed(int unicodeChar) override;

	//
	// Загрузка настроек уровня
	//
	bool LoadLevelSettings();

	//
	// Установка эффекта в указанных координатах
	//
	void SetEffect(std::string effect_name, float x, float y);

private:
	void Init();

private:
	float _timer;

	bool isWin = false;
	bool isLose = false;

	GameObject background = GameObject("Background"); // Фоновое изображение

	EffectsContainer _effCont;
	ParticleEffectPtr _eff;

	size_t _simpleEnemiesCount; // Количество простых врагов
	size_t _armoredEnemiesCount; // Количество бронированных врагов
	size_t _enemiesCount; // Общее количество врагов

	gameTimer myTimer;
	Gun myGun;
	Cursor myCursor;

	std::vector<SimpleEnemy*> EnemiesCollection;
	std::vector<Bullet*> BulletsCollection;

	std::vector<SimpleEnemy*>::iterator other_enemy;

};

