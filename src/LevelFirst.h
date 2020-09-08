#pragma once
#include "GameObject.h"
#include "MovableTarget.h"
#include "Bullet.h"
class LevelFirst : public GUI::Widget
{
public:
	LevelFirst(const std::string& name, rapidxml::xml_node<>* elem);

	void Draw() override;
	void Update(float dt) override;

	void AcceptMessage(const Message& message) override;

	bool MouseDown(const IPoint& mouse_pos) override;
	void MouseMove(const IPoint& mouse_pos) override;
	void MouseUp(const IPoint& mouse_pos) override;

	void KeyPressed(int keyCode) override;
	void CharPressed(int unicodeChar) override;

private:
	void Init();
private:
	float _timer;

	float _scale;

	int _curTex;

	EffectsContainer _effCont;
	ParticleEffectPtr _eff;

	TimedSpline<FPoint> spline;

	size_t EnemiesCount;
	std::vector<MovableTarget*> EnemiesCollection;
	std::vector<Bullet*> BulletsCollection;

};

