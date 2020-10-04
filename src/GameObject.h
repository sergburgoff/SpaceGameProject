#pragma once
class GameObject
{
public:
	GameObject(std::string texture_name);

	virtual void Draw();
	static bool CheckObjectCollision(GameObject *first,
		GameObject *second);

	void setPosition(float x, float y);
	void Rotate(float _angle);
	void Scale(float width, float hight);

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

