#pragma once

#define SIZE_COEF 15.f

class Settings
{
public:
	static void setBorders();

	static bool LoadSettings();

public:
	//
	// Размеры окна
	//
	static int WINDOW_WIDTH;
	static int WINDOW_HEIGHT;

	//
	// Размеры игрового поля
	//
	static int BOTTOM_BORDER;
	static int TOP_BORDER;
	static int RIGHT_BORDER;
	static int LEFT_BORDER;

	static int RELOADING_TIME; // Время перезарядки орудия

	//
	// Скорости объектов
	//
	static float BULLET_SPEED;
	static float SIMPLE_ENEMIES_SPEED;
	static float ARMORED_ENEMIES_SPEED;
};

