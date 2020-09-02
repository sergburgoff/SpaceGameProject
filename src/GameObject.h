#pragma once
class GameObject
{
public:
	GameObject(std::string texture_name);
	~GameObject();

	virtual void Draw(float pos_x, float pos_y);

	virtual void Death_Animation() = 0;
	void setTexture(std::string texture_name);
	Render::texture & getTexture();
	//Position	
	//Width, Hight
protected:
	Render::texture* _texture;
	
	float scale_x, scale_y;
	float _angle;

};

