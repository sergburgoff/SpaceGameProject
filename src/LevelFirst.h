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

	void ClearScreen();

	void AcceptMessage(const Message& message) override;

	bool MouseDown(const IPoint& mouse_pos) override;
	void MouseMove(const IPoint& mouse_pos) override;
	void MouseUp(const IPoint& mouse_pos) override;

	void KeyPressed(int keyCode) override;
	void CharPressed(int unicodeChar) override;

	bool Deserialisation();

private:
	void Init();

private:
	float _timer;

	bool isWin = false;
	bool isLose = false;

	EffectsContainer _effCont;
	ParticleEffectPtr _eff;

	size_t _simpleEnemiesCount;
	size_t _armoredEnemiesCount;
	size_t _enemiesCount;

	gameTimer myTimer;
	Gun myGun;
	Cursor myCursor;

	std::vector<SimpleEnemy*> EnemiesCollection;
	std::vector<Bullet*> BulletsCollection;

	std::vector<SimpleEnemy*>::iterator other_enemy;

};

