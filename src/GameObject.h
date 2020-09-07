#pragma once
class GameObject
{
public:
	GameObject(std::string texture_name);

	virtual void Draw();
	
	void setPosition(float x, float y);
	void Rotate(float _angle);
	void Scale(float width, float hight);

	float getX();
	float getY();
	float getWidth();
	float getHeight();

	void setTexture(std::string texture_name);
	Render::Texture& getTexture();
	virtual bool CheckCollision(GameObject *other);
protected:
	float x, y;
	float width, height;
	float _angle;

	Render::Texture* _texture;

};

