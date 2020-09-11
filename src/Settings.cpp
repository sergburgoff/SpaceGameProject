#include "stdafx.h"
#include "Settings.h"

int Settings::WINDOW_WIDTH;
int Settings::WINDOW_HEIGHT;
int Settings::BOTTOM_BORDER;
int Settings::TOP_BORDER;
int Settings::RIGHT_BORDER;
int Settings::LEFT_BORDER;

void Settings::setBorders()
{
	Settings::BOTTOM_BORDER = 20;
	Settings::TOP_BORDER = Settings::WINDOW_HEIGHT - 10;
	Settings::LEFT_BORDER = 20;
	Settings::RIGHT_BORDER = Settings::WINDOW_WIDTH - 10;
}
