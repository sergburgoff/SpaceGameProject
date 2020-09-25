#pragma once

#define SIZE_COEF 15.f

class Settings
{
public:
	static void setBorders();

	static void Serialisation();
	static void Deserialisation();
public:
	static int WINDOW_WIDTH;
	static int WINDOW_HEIGHT;

	static int BOTTOM_BORDER;
	static int TOP_BORDER;
	static int RIGHT_BORDER;
	static int LEFT_BORDER;
};

