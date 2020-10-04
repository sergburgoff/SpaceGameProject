#include "stdafx.h"
#include "Settings.h"
#include <iostream>
#include <fstream>

int Settings::WINDOW_WIDTH;
int Settings::WINDOW_HEIGHT;
int Settings::BOTTOM_BORDER;
int Settings::TOP_BORDER;
int Settings::RIGHT_BORDER;
int Settings::LEFT_BORDER;
int Settings::RELOADING_TIME;

float Settings::BULLET_SPEED;
float Settings::SIMPLE_ENEMIES_SPEED;
float Settings::ARMORED_ENEMIES_SPEED;

void Settings::setBorders()
{
	Settings::BOTTOM_BORDER = 20;
	Settings::TOP_BORDER = Settings::WINDOW_HEIGHT - 10;
	Settings::LEFT_BORDER = 20;
	Settings::RIGHT_BORDER = Settings::WINDOW_WIDTH - 10;
}

bool Settings::LoadSettings()
{
	std::ifstream input;

	input.open("base_p/settings.txt");

	if (!input.is_open())
		return false;
	
	std::string inLine;

	input >> inLine;
	input >> inLine;
	BULLET_SPEED = std::stof(inLine);
	input >> inLine;
	input >> inLine;
	SIMPLE_ENEMIES_SPEED = std::stof(inLine);
	input >> inLine;
	input >> inLine;
	ARMORED_ENEMIES_SPEED = std::stof(inLine);
	input >> inLine;
	input >> inLine;
	RELOADING_TIME = std::stof(inLine);

	input.close();

	return true;
}