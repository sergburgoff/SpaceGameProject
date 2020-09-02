#include "stdafx.h"
#include "LevelFirst.h"
#include "GameObject.h"
#include "Gun.h"

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
}

void LevelFirst::Draw()
{
	

}

void LevelFirst::Update(float dt)
{
	
}

bool LevelFirst::MouseDown(const IPoint &mouse_pos)
{
	
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
