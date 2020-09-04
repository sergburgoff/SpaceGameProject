#pragma once
class GameObject
{
public:
	GameObject(std::string texture_name);

	virtual void Draw();
	
	void setPosition(float x, float y);
	void Rotate(float _angle);
	void Scale(float width, float hight);

	virtual void DeathAnimation() = 0;
	void setTexture(std::string texture_name);
	Render::Texture& getTexture();
	virtual bool CheckCollision(GameObject &other);

public:
	float x = 0, y = 0;
	float width = 0, hight = 0;
protected:
	
	Render::Texture* _texture;
	
	float _angle = 0;

};

