#include "stdafx.h"
#include <random>
#include <time.h>
#include <chrono>
#include <thread>
#include "SimpleEnemy.h"

enum {
	WINDOW_WIDTH = 1024,
	WINDOW_HEIGHT = 768
};

bool SimpleEnemy::CheckCollision(GameObject &other)
{
	if (this->x < other.x + other.width &&
		this->x + this->width > other.x &&
		this->y < other.y + other.hight &&
		this->y + this->hight > other.y)
	{
		/*if (other.type == "Bullet")
			DeathAnimation();
		return 1;*/
	}
	return 0;
}

SimpleEnemy::SimpleEnemy() : GameObject("SimpleEnemy")
{
	Scale(100.0f, 100.0f);
	x = Random(1.0f, (float)WINDOW_WIDTH);
	std::this_thread::sleep_for(std::chrono::seconds(1));
	y = Random(1.0f, (float)WINDOW_HEIGHT);
	ChooseRandDirection();
}

inline int SimpleEnemy::Random(int min, int max)
{
	srand(std::time(NULL) * 3);
	std::mt19937 gen(std::time(NULL) + rand());
	std::uniform_int_distribution<int> dis(min, max);
	return dis(gen);
}

inline float SimpleEnemy::Random(float min, float max)
{
	srand(std::time(NULL) * 3);
	std::mt19937 gen(std::time(NULL) + rand());
	std::uniform_real_distribution<float> dis(min, max);
	return dis(gen);
}


void SimpleEnemy::ChooseRandDirection()
{
	float point_x, point_y;
	SplinePath<FPoint> spline;
	
	switch (Random(1, 4))
	{
	case 1:
		point_x = 0;
		point_y = Random(1.0f, (float)WINDOW_HEIGHT);
		break;
	case 2:
		point_x = Random(1.0f, (float)WINDOW_WIDTH);
		point_y = (float)WINDOW_HEIGHT;
		break;
	case 3:
		point_x = (float)WINDOW_WIDTH;
		point_y = Random(1.0f, (float)WINDOW_HEIGHT);
		break;
	case 4:
		point_x = Random(1.0f, (float)WINDOW_WIDTH);
		point_y = 0;
		break;
	}
	//_angle = (180 / math::PI) * -math::atan(point_y - y,
	//	point_x - x);
	//spline.addKey(FPoint(x, y));
}

void SimpleEnemy::DeathAnimation()
{

}