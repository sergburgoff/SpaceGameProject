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

bool Settings::Serialisation()
{
	return 0;
}

bool Settings::Deserialisation()
{
	std::ifstream input;

	input.open("settings.txt");

	if (!input.is_open())
		return false;
	
	std::string inLine;

	input >> inLine;
	BULLET_SPEED = std::stoi(inLine);
	input >> inLine;
	SIMPLE_ENEMIES_SPEED = std::stoi(inLine);
	input >> inLine;
	ARMORED_ENEMIES_SPEED = std::stoi(inLine);
	input >> inLine;
	RELOADING_TIME = std::stoi(inLine);

	input.close();

	return true;
}