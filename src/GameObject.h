#pragma once
class GameObject
{
public:
	GameObject(std::string texture_name);

	virtual void Draw(); // Метод отрисовки объекта

	//
	// Проверка столкновений объектов.
	// Может быть так же использовано для курсора и изменения его состояния при наведении 
	// на какие-либо объекты
	//
	static bool CheckObjectCollision(GameObject *first,
		GameObject *second); 

	void setPosition(float x, float y); // Установка позиции объекта
	void Scale(float width, float hight); // Установка размеров объекта

	float getX();
	float getY();
	float getWidth();
	float getHeight();

	void setTexture(std::string texture_name);
	Render::Texture& getTexture();

protected:
	float x, y;
	float width, height;
	float _angle;

	Render::Texture* _texture;

};

