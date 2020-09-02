#pragma once
class GameObject
{
public:
	GameObject(std::string texture_name);
	~GameObject();

	virtual void Draw(float pos_x, float pos_y);

	virtual void DeathAnimation() = 0;
	void setTexture(std::string texture_name);
	Render::Texture& getTexture();
	virtual bool CheckCollision(GameObject &one, GameObject &two);

	std::string type;
	float x, y;
	float scale_x, scale_y;
protected:
	Render::Texture* _texture;
	
	float _angle;

};

