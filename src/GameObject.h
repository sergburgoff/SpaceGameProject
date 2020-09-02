#pragma once
class GameObject
{
public:
	GameObject(std::string texture_name);

	virtual void Draw(float pos_x, float pos_y);

	virtual void DeathAnimation() = 0;
	void setTexture(std::string texture_name);
	Render::Texture& getTexture();
	static bool CheckCollision(GameObject &one, GameObject &two);

	std::string type;
	float x, y;
	float scale_x = 0, scale_y = 0;
protected:
	Render::Texture* _texture;
	
	float _angle;

};

