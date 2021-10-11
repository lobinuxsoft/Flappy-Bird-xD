#pragma once
#include "class/Entity.h"

class Player : public Entity
{
private:
	const float defaultRadius = 18.0;
	const float speed = 100;

	Texture2D sprite;
	Sound jumpSfx;
	Rectangle rect{ 0,0,0,0 };
	Vector2 pivot = { 0, 0 };
	Vector2 startPosition = { 0,0 };
	float rotation = 0;
	float radius = defaultRadius;
	bool isAlive = true;

private:
	void screenLimitsLogic();
	void movement();

public:
	Player(Vector2 position, const char spriteUrl[], const char jumpSfxUrl[]);
	~Player() override;
	void setPivot(Vector2 pivot);
	float getRadius();
	void setIsAlive(bool isAlive);
	bool getIsAlive();
	void update();
	void draw();
};

