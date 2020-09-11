#pragma once

#define SIZE_COEF 15.f

enum { // ”¡–¿“‹!
	WINDOW_WIDTH = 1000,
	WINDOW_HEIGHT = 760
};

enum { // ”¡–¿“‹!
	BOTTOM_BORDER = 60,
	TOP_BORDER = 755,
	RIGHT_BORDER = 1000,
	LEFT_BORDER = -10
};

class Settings
{
public:
	static void setBorders();
public:
	static int WINDOW_WIDTH;
	static int WINDOW_HEIGHT;

	static int BOTTOM_BORDER;
	static int TOP_BORDER;
	static int RIGHT_BORDER;
	static int LEFT_BORDER;
};

